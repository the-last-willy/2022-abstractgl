#pragma once

#include <agl/engine/all.hpp>

#include <tiny_obj_loader.h>

#include <filesystem>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace agl::format::wavefront {

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
        eng_material.uniforms["baseColorFactor"]
        = new eng::Uniform<agl::Vec4>(agl::vec4(
            material.ambient[0],
            material.ambient[1],
            material.ambient[2],
            1.f));
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
                for(std::size_t j = 0; j < size(mesh.indices); ++j) {
                    auto idx = mesh.indices[j];
                    indices[j] = static_cast<unsigned>(j);
                    if(idx.normal_index >= 0) {
                        normals[j] = agl::vec3(
                            attrib.normals[3 * idx.normal_index + 0],
                            attrib.normals[3 * idx.normal_index + 1],
                            attrib.normals[3 * idx.normal_index + 2]);
                    }
                    positions[j] = agl::vec3(
                        attrib.vertices[3 * idx.vertex_index + 0],
                        attrib.vertices[3 * idx.vertex_index + 1],
                        attrib.vertices[3 * idx.vertex_index + 2]);
                    if(idx.texcoord_index >= 0) {
                        texcoords[j] = agl::vec2(
                            attrib.texcoords[2 * idx.texcoord_index + 0],
                            attrib.texcoords[2 * idx.texcoord_index + 1]);
                    }
                }
                eng_primitive.attributes["NORMAL"] = agl::engine::accessor(
                    std::span(normals));
                eng_primitive.attributes["POSITION"] = agl::engine::accessor(
                    std::span(positions));
                eng_primitive.attributes["TEXCOORDS_0"] = agl::engine::accessor(
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
