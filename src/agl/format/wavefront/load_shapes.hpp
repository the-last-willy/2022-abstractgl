#pragma once

#include "content.hpp"

#include <tiny_obj_loader.h>

#include <stdexcept>

namespace agl::format::wavefront {

inline
void load_shapes(
    Content& content,
    const tinyobj::ObjReader& obj)
{
    auto& attrib = obj.GetAttrib();
    auto& shapes = obj.GetShapes();
    content.meshes.resize(size(shapes));
    for(std::size_t i = 0; i < size(shapes); ++i) {
        auto& mesh = shapes[i].mesh;
        auto& eng_mesh = *(content.meshes[i] = std::make_shared<eng::Mesh>());

        auto indices = std::vector<unsigned>(size(mesh.indices));
        auto normals = std::vector<agl::Vec3>(size(mesh.indices));
        auto positions = std::vector<agl::Vec3>(size(mesh.indices));
        auto texcoords = std::vector<agl::Vec2>(size(mesh.indices));

        // Load a primitive per material group.
        // For each face.
        for(std::size_t f = 0; f < size(mesh.num_face_vertices);) {
            auto& eng_primitive = *(eng_mesh.primitives.emplace_back(
                std::make_shared<eng::Primitive>()));
            auto material_group = mesh.material_ids[f];
            if(material_group >= 0) {
                eng_primitive.material = content.materials[material_group];
            }
            
            indices.clear();
            normals.clear();
            positions.clear();
            texcoords.clear();

            for(; f < size(mesh.num_face_vertices); ++f) {
                if(mesh.num_face_vertices[f] != 3) {
                    throw std::logic_error(
                        "agl::format::wavefront: "
                        "Supports only faces with 3 vertices.");
                }
                if(mesh.material_ids[f] == material_group) {
                    for(std::size_t j = 0; j < mesh.num_face_vertices[f]; ++j) {
                        auto idx = mesh.indices[3 * f + j];
                        indices.emplace_back(static_cast<unsigned>(f));
                        if(idx.normal_index >= 0) {
                            normals.emplace_back(agl::vec3(
                                attrib.normals[3 * idx.normal_index + 0],
                                attrib.normals[3 * idx.normal_index + 1],
                                attrib.normals[3 * idx.normal_index + 2]));
                        }
                        { // Position.
                            positions.emplace_back(agl::vec3(
                                attrib.vertices[3 * idx.vertex_index + 0],
                                attrib.vertices[3 * idx.vertex_index + 1],
                                attrib.vertices[3 * idx.vertex_index + 2]));
                        }
                        if(idx.texcoord_index >= 0) {
                            texcoords.emplace_back(agl::vec2(
                                attrib.texcoords[2 * idx.texcoord_index + 0],
                                attrib.texcoords[2 * idx.texcoord_index + 1]));
                        }
                    }
                } else {
                    break;
                }
            }
            eng_primitive.attributes["vn"] = agl::engine::accessor(
                std::span(normals));
            eng_primitive.attributes["v"] = agl::engine::accessor(
                std::span(positions));
            eng_primitive.attributes["vt"] = agl::engine::accessor(
                std::span(texcoords));
            eng_primitive.draw_type = agl::DrawType::unsigned_int;
            eng_primitive.indices = agl::engine::accessor(
                std::span(indices));
            eng_primitive.primitive_count =  agl::Count<GLsizei>(
                static_cast<GLsizei>(3 * size(indices)));
        }
        
        
        // OLD WAY.
        // { // Load primitive.
        //     auto& eng_primitive = *(eng_mesh.primitives.emplace_back(
        //         std::make_shared<eng::Primitive>()));
        //     if(mesh.material_ids.front() >= 0) {
        //         eng_primitive.material = content.materials[mesh.material_ids.front()];
        //     }
        //     { // Positions.
        //         auto indices = std::vector<unsigned>(size(mesh.indices));
        //         auto normals = std::vector<agl::Vec3>(size(mesh.indices));
        //         auto positions = std::vector<agl::Vec3>(size(mesh.indices));
        //         auto texcoords = std::vector<agl::Vec2>(size(mesh.indices));
        //         auto pmin = agl::vec3(
        //             attrib.vertices[0],
        //             attrib.vertices[1],
        //             attrib.vertices[2]);
        //         auto pmax = pmin;
        //         for(std::size_t f = 0; f < size(mesh.indices); ++f) {
        //             auto idx = mesh.indices[f];
        //             indices[f] = static_cast<unsigned>(f);
        //             if(idx.normal_index >= 0) {
        //                 normals[f] = agl::vec3(
        //                     attrib.normals[3 * idx.normal_index + 0],
        //                     attrib.normals[3 * idx.normal_index + 1],
        //                     attrib.normals[3 * idx.normal_index + 2]);
        //             }
        //             { // Position.
        //                 auto p = positions[f] = agl::vec3(
        //                     attrib.vertices[3 * idx.vertex_index + 0],
        //                     attrib.vertices[3 * idx.vertex_index + 1],
        //                     attrib.vertices[3 * idx.vertex_index + 2]);
        //                 if(p[0] < pmin[0]) {
        //                     pmin[0] = p[0];
        //                 } else if(p[0] > pmax[0]) {
        //                     pmax[0] = p[0];
        //                 }
        //                 if(p[1] < pmin[1]) {
        //                     pmin[1] = p[1];
        //                 } else if(p[1] > pmax[1]) {
        //                     pmax[1] = p[1];
        //                 }
        //                 if(p[2] < pmin[2]) {
        //                     pmin[2] = p[2];
        //                 } else if(p[2] > pmax[2]) {
        //                     pmax[2] = p[2];
        //                 }
        //             }
        //             if(idx.texcoord_index >= 0) {
        //                 texcoords[f] = agl::vec2(
        //                     attrib.texcoords[2 * idx.texcoord_index + 0],
        //                     attrib.texcoords[2 * idx.texcoord_index + 1]);
        //             }
        //         }
        //         eng_primitive.attributes["vn"] = agl::engine::accessor(
        //             std::span(normals));
        //         eng_primitive.attributes["v"] = agl::engine::accessor(
        //             std::span(positions));
        //         {
        //             eng_primitive.attributes["v"].min.resize(3);
        //             eng_primitive.attributes["v"].min[0] = pmin[0];
        //             eng_primitive.attributes["v"].min[1] = pmin[1];
        //             eng_primitive.attributes["v"].min[2] = pmin[2];
        //             eng_primitive.attributes["v"].max.resize(3);
        //             eng_primitive.attributes["v"].max[0] = pmax[0];
        //             eng_primitive.attributes["v"].max[1] = pmax[1];
        //             eng_primitive.attributes["v"].max[2] = pmax[2];
        //         }
        //         eng_primitive.attributes["vt"] = agl::engine::accessor(
        //             std::span(texcoords));
        //         eng_primitive.draw_type = agl::DrawType::unsigned_int;
        //         eng_primitive.indices = agl::engine::accessor(
        //             std::span(indices));
        //         eng_primitive.primitive_count =  agl::Count<GLsizei>(
        //             static_cast<GLsizei>(size(mesh.indices)));
        //     }
        // }
    }
}

}
