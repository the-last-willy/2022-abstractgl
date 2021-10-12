#pragma once

#include "content.hpp"
#include "load_texture.hpp"

#include <tiny_obj_loader.h>

namespace agl::format::wavefront {

inline
void load_materials(
    Content& content,
    const tinyobj::ObjReader& obj,
    const std::filesystem::path& mtl_path)
{
    auto& materials = obj.GetMaterials();
    content.materials.resize(size(materials));
    for(std::size_t i = 0; i < size(materials); ++i) {
        auto& material = materials[i];
        auto& eng_material = *(content.materials[i]
            = std::make_shared<eng::Material>());
        { // Kd/map_Kd.
            if(not empty(material.diffuse_texname)) {
                eng_material.textures["map_Kd"]
                = std::make_shared<eng::Texture>(
                    load_texture((mtl_path.string() + material.diffuse_texname).c_str(), 4));
            }
            
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
}

}
