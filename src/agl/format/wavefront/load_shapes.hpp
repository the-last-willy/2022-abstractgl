#pragma once

#include "content.hpp"

#include <tiny_obj_loader.h>

#include <fstream>
#include <map>
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

            auto vertex_indices = std::map<std::array<int, 3>, unsigned>();

            for(; f < size(mesh.num_face_vertices); ++f) {                
                if(mesh.num_face_vertices[f] != 3) {
                    throw std::logic_error(
                        "agl::format::wavefront: "
                        "Supports only faces with 3 vertices.");
                }
                if(mesh.material_ids[f] == material_group) {
                    for(std::size_t j = 0; j < mesh.num_face_vertices[f]; ++j) {
                        auto idx = mesh.indices[3 * f + j];
                        auto idx_array = std::array{
                            idx.vertex_index,
                            idx.normal_index,
                            idx.texcoord_index};
                        auto it = vertex_indices.find(idx_array);
                        if(it == end(vertex_indices)) {
                            auto vertex_index = static_cast<unsigned>(size(vertex_indices));
                            vertex_indices[idx_array] = vertex_index;
                            indices.emplace_back(vertex_index);
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
                        } else {
                            indices.emplace_back(it->second);
                        }
                    }
                } else {
                    vertex_indices.clear();
                    break;
                }
            }
            if(not empty(normals)) {
            eng_primitive.attributes["vn"] = agl::engine::accessor(
                std::span(normals));
            }
            eng_primitive.attributes["v"] = agl::engine::accessor(
                std::span(positions));
            if(not empty(texcoords)) {
                eng_primitive.attributes["vt"] = agl::engine::accessor(
                    std::span(texcoords));
            }
            eng_primitive.draw_type = agl::DrawType::unsigned_int;
            eng_primitive.indices = agl::engine::accessor(
                std::span(indices));
            eng_primitive.primitive_count =  agl::Count<GLsizei>(
                static_cast<GLsizei>(3 * size(indices)));
        }
    }
    // Compute bounding boxes.
    for(std::size_t s = 0; s < size(shapes); ++s) {
        auto& mesh = shapes[s].mesh;
        auto& eng_mesh = content.meshes[s];
        auto& bb_min = eng_mesh->bb_min;
        auto& bb_max = eng_mesh->bb_max;
        {
            bb_min = bb_max = agl::vec3(
                attrib.vertices[3 * mesh.indices[0].vertex_index + 0],
                attrib.vertices[3 * mesh.indices[0].vertex_index + 1],
                attrib.vertices[3 * mesh.indices[0].vertex_index + 2]);
        }
        for(std::size_t i = 1; i < size(mesh.indices); ++i) {
            auto v = agl::vec3(
                attrib.vertices[3 * mesh.indices[i].vertex_index + 0],
                attrib.vertices[3 * mesh.indices[i].vertex_index + 1],
                attrib.vertices[3 * mesh.indices[i].vertex_index + 2]);
            if(v[0] < bb_min[0]) {
                bb_min[0] = v[0];
            } else if(v[0] > bb_max[0]) {
                bb_max[0] = v[0];
            }
            if(v[1] < bb_min[1]) {
                bb_min[1] = v[1];
            } else if(v[1] > bb_max[1]) {
                bb_max[1] = v[1];
            }
            if(v[2] < bb_min[2]) {
                bb_min[2] = v[2];
            } else if(v[2] > bb_max[2]) {
                bb_max[2] = v[2];
            }
        }
    }
}

}
