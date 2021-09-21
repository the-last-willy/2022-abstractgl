#pragma once

#include <agl/engine/all.hpp>

#include <stb_image.h>
#include <stb_image_resize.h>
#include <tiny_obj_loader.h>

#include <filesystem>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace agl::format::wavefront {

inline
auto load_texture(std::string filepath, int) {

    int w, h, n;
    unsigned char *data = stbi_load(filepath.c_str(), &w, &h, &n, 0);
    if(data == NULL) {
        throw std::runtime_error("stb_image: Failure.");
    }

    // auto dw = w / factor;
    // auto dh = w / factor;
    // auto downsampled = std::vector<unsigned char>(n * dw * dh);

    // auto r = stbir_resize_uint8(
    //     data, w, h, 0,
    //     downsampled.data(), dw, dh, 0,
    //     n);
    // if(r == 0) {
    //     throw std::runtime_error("stb_image_resize: Failure.");
    // }

    auto t = agl::create(agl::TextureTarget::_2d);
    GLenum base_internal_format = 0;
    GLenum pixel_data_type = 0;
    GLenum sized_internal_format = 0;
    if(n == 3) {
        base_internal_format = GL_RGB;
        pixel_data_type = GL_UNSIGNED_BYTE;
        sized_internal_format = GL_RGB8;
    } else if(n == 4) {
        base_internal_format = GL_RGBA;
        pixel_data_type = GL_UNSIGNED_BYTE;
        sized_internal_format = GL_RGBA8;
    } else {
        throw std::runtime_error("Invalid texture format.");
    }
    auto level_count = static_cast<GLsizei>(
        std::floor(std::log2(std::max(h, w))) + 1);
    agl::storage(
            t, level_count, sized_internal_format,
            agl::Width(w), agl::Height(h));
    agl::image(
        t, agl::Width(w), agl::Height(h),
        base_internal_format, pixel_data_type,
        std::as_bytes(std::span(data, w * h * n)));
    agl::generate_mipmap(t);

    stbi_image_free(data);

    auto et = eng::Texture();
    et.texture = t;
    return et;
}

struct Content {
    std::vector<std::shared_ptr<eng::Material>> materials;
    std::vector<std::shared_ptr<eng::Mesh>> meshes;
};

struct Wavefront {
    tinyobj::attrib_t attrib;

    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
};

inline
Content load(
    const std::filesystem::path& obj_path,
    const std::filesystem::path& mtl_path)
{
    stbi_set_flip_vertically_on_load(true);

    tinyobj::ObjReaderConfig reader_config;
    reader_config.mtl_search_path = mtl_path.string();

    tinyobj::ObjReader reader;

    if (!reader.ParseFromFile(obj_path.string(), reader_config)) {
        if (!reader.Error().empty()) {
            std::cerr << "TinyObjReader: " << reader.Error();
        }
        throw std::runtime_error("TinyObjReader: Failed.");
    }

    if(!reader.Warning().empty()) {
        std::cout << "TinyObjReader: " << reader.Warning();
    }

    auto& attrib = reader.GetAttrib();
    auto& shapes = reader.GetShapes();
    auto& materials = reader.GetMaterials();

    auto content = Content();

    content.materials.resize(size(materials));
    for(std::size_t i = 0; i < size(materials); ++i) {
        auto& material = materials[i];
        auto& eng_material = *(content.materials[i]
            = std::make_shared<eng::Material>());
        { // Kd/map_Kd.
            eng_material.textures["map_Kd"]
            = std::make_shared<eng::Texture>(
                load_texture((mtl_path.string() + material.diffuse_texname).c_str(), 4));
            eng_material.uniforms["Kd"]
            = new eng::Uniform<agl::Vec3>(agl::vec3(
                material.diffuse[0],
                material.diffuse[1],
                material.diffuse[2]));
        }
        { // Ke/map_ke.
            // TINYOBJLOADER Ke WHERE ?
            // eng_material.uniforms["Ke"]
            // = new eng::Uniform<agl::Vec4>(agl::vec4(
            //     material.ambient[0],
            //     material.ambient[1],
            //     material.ambient[2],
            //     1.f));
            if(not empty(material.emissive_texname)) {
                eng_material.textures["map_Ke"]
                = std::make_shared<eng::Texture>(
                    load_texture((mtl_path.string() + material.emissive_texname).c_str(), 4));
            }
        }
        { // Ks/map_Ks.
            // eng_material.textures["map_Ks"]
            // = std::make_shared<eng::Texture>(
            //     load_texture((mtl_path.string() + material.specular_texname).c_str(), 4));
            eng_material.uniforms["Ks"]
            = new eng::Uniform<agl::Vec3>(agl::vec3(
                material.specular[0],
                material.specular[1],
                material.specular[2]));
        }
        { // map_Bump.
            // eng_material.textures["map_Bump"]
            // = std::make_shared<eng::Texture>(
            //     load_texture((mtl_path.string() + material.bump_texname).c_str(), 4));
        }
        { // Ns.
            eng_material.uniforms["Ns"]
            = new eng::Uniform<float>(material.shininess);
        }
    }

    content.meshes.resize(size(shapes));
    for(std::size_t i = 0; i < size(shapes); ++i) {
        auto& mesh = shapes[i].mesh;
        auto& eng_mesh = *(content.meshes[i] = std::make_shared<eng::Mesh>());
        { // Load primitive.
            auto& eng_primitive = *(eng_mesh.primitives.emplace_back(
                std::make_shared<eng::Primitive>()));
            if(mesh.material_ids.front() >= 0) {
                eng_primitive.material = content.materials[mesh.material_ids.front()];
            }
            { // Positions.
                auto indices = std::vector<unsigned>(size(mesh.indices));
                auto normals = std::vector<agl::Vec3>(size(mesh.indices));
                auto positions = std::vector<agl::Vec3>(size(mesh.indices));
                auto texcoords = std::vector<agl::Vec2>(size(mesh.indices));
                auto pmin = agl::vec3(
                    attrib.vertices[0],
                    attrib.vertices[1],
                    attrib.vertices[2]);
                auto pmax = pmin;
                for(std::size_t j = 0; j < size(mesh.indices); ++j) {
                    auto idx = mesh.indices[j];
                    indices[j] = static_cast<unsigned>(j);
                    if(idx.normal_index >= 0) {
                        normals[j] = agl::vec3(
                            attrib.normals[3 * idx.normal_index + 0],
                            attrib.normals[3 * idx.normal_index + 1],
                            attrib.normals[3 * idx.normal_index + 2]);
                    }
                    {
                        auto p = positions[j] = agl::vec3(
                            attrib.vertices[3 * idx.vertex_index + 0],
                            attrib.vertices[3 * idx.vertex_index + 1],
                            attrib.vertices[3 * idx.vertex_index + 2]);
                        if(p[0] < pmin[0]) {
                            pmin[0] = p[0];
                        } else if(p[0] > pmax[0]) {
                            pmax[0] = p[0];
                        }
                        if(p[1] < pmin[1]) {
                            pmin[1] = p[1];
                        } else if(p[1] > pmax[1]) {
                            pmax[1] = p[1];
                        }
                        if(p[2] < pmin[2]) {
                            pmin[2] = p[2];
                        } else if(p[2] > pmax[2]) {
                            pmax[2] = p[2];
                        }
                    }
                    if(idx.texcoord_index >= 0) {
                        texcoords[j] = agl::vec2(
                            attrib.texcoords[2 * idx.texcoord_index + 0],
                            attrib.texcoords[2 * idx.texcoord_index + 1]);
                    }
                }
                eng_primitive.attributes["vn"] = agl::engine::accessor(
                    std::span(normals));
                eng_primitive.attributes["v"] = agl::engine::accessor(
                    std::span(positions));
                {
                    eng_primitive.attributes["v"].min.resize(3);
                    eng_primitive.attributes["v"].min[0] = pmin[0];
                    eng_primitive.attributes["v"].min[1] = pmin[1];
                    eng_primitive.attributes["v"].min[2] = pmin[2];
                    eng_primitive.attributes["v"].max.resize(3);
                    eng_primitive.attributes["v"].max[0] = pmax[0];
                    eng_primitive.attributes["v"].max[1] = pmax[1];
                    eng_primitive.attributes["v"].max[2] = pmax[2];
                }
                eng_primitive.attributes["vt"] = agl::engine::accessor(
                    std::span(texcoords));
                eng_primitive.draw_type = agl::DrawType::unsigned_int;
                eng_primitive.indices = agl::engine::accessor(
                    std::span(indices));
                eng_primitive.primitive_count =  agl::Count<GLsizei>(
                    static_cast<GLsizei>(size(mesh.indices)));
            }
        }
    }

    return content;
}

}
