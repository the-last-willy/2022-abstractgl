#pragma once

#include "content.hpp"

#include "agl/engine/triangle_mesh/all.hpp"
#include "agl/geometry/all.hpp"

#include <tiny_obj_loader.h>

#include <fstream>
#include <map>
#include <stdexcept>

namespace agl::format::wavefront {

inline
agl::engine::TriangleMesh load_geometry(
    const tinyobj::ObjReader& obj)
{
    auto m = agl::engine::TriangleMesh();

    auto& attrib = obj.GetAttrib();
    auto& shapes = obj.GetShapes();

    // Loop over shapes
    for (size_t s = 0; s < shapes.size(); s++) {
        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);

            // Loop over vertices in the face.
            for (size_t v = 0; v < fv; v++) {
                topology(m).face_indices.push_back(static_cast<uint32_t>(size(topology(m).face_indices)));

                // access to vertex
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

                geometry(m).vertex_material_ids.push_back(shapes[s].mesh.material_ids[f]);

                geometry(m).vertex_positions.push_back(agl::vec3(
                    attrib.vertices[3*size_t(idx.vertex_index)+0],
                    attrib.vertices[3*size_t(idx.vertex_index)+1],
                    attrib.vertices[3*size_t(idx.vertex_index)+2]));

                // Check if `normal_index` is zero or positive. negative = no normal data
                if (idx.normal_index >= 0) {
                    geometry(m).vertex_normals.push_back(agl::vec3(
                        attrib.normals[3*size_t(idx.normal_index)+0],
                        attrib.normals[3*size_t(idx.normal_index)+1],
                        attrib.normals[3*size_t(idx.normal_index)+2]));
                }

                // Check if `texcoord_index` is zero or positive. negative = no texcoord data
                if (idx.texcoord_index >= 0) {
                    geometry(m).vertex_texcoords.push_back(agl::vec2(
                        attrib.texcoords[2*size_t(idx.texcoord_index)+0],
                        attrib.texcoords[2*size_t(idx.texcoord_index)+1]));
                }
            }
            index_offset += fv;

            // per-face material
            // shapes[s].mesh.material_ids[f];
        }
    }

    return m;
}

inline
agl::engine::TriangleMesh load_geometry(
    const std::filesystem::path& file_path)
{
    tinyobj::ObjReaderConfig reader_config;

    tinyobj::ObjReader reader;

    if (!reader.ParseFromFile(file_path.string(), reader_config)) {
        if (!reader.Error().empty()) {
            std::cerr << "TinyObjReader: " << reader.Error();
        }
        throw std::runtime_error("TinyObjReader: Failed.");
    }

    if(!reader.Warning().empty()) {
        std::cout << "TinyObjReader: " << reader.Warning();
    }

    return load_geometry(reader);
}

inline
void load_geometry(
    Content& content,
    const tinyobj::ObjReader& obj)
{
    auto g = load_geometry(obj);
    content.tmeshes.push_back(
        std::make_shared<agl::engine::TriangleMesh>(std::move(g)));
}

}
