#pragma once

#include <agl/engine/database/database.hpp>

#include <filesystem>
#include <iostream>
#include <stdexcept>

namespace agl::format::wavefront {

struct Wavefront {
    tinyobj::attrib_t attrib;

    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
};

inline
engine::Database load(const std::filesystem::path& p) {
    auto wavefront = Wavefront();

    std::string warn;
    std::string err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, p.c_str());

    if (!warn.empty()) {
        std::cout << warn << std::endl;
    }

    if (!err.empty()) {
        std::cerr << err << std::endl;
    }

    if (!ret) {
        throw std::runtime_error(
            "agl::format::wavefront: Failed to read file.");
    }

    auto database = engine::Database();

    for (std::size_t i = 0; i < size(wavefront.shapes); ++i) {
        auto& shape = wavefront.shapes[i];
        { // Mesh.
            auto mesh = shape.mesh;
            auto eng_mesh = database.meshes[i];
            auto eng_primitive = *(eng_mesh.primitives.emplace_back(
                std::make_shared<eng::Primitive>()));
            for(auto nfc : mesh.num_face_vertices) {
                if(nfc != 3) {
                    throw std::runtime_error(
                        "agl::format::wavefront: Only faces with 3 vertices are currently handled.");
                }
            }
            { // Index bufer.
                auto eng_buffer_id = size(database.buffers);
                auto& eng_buffer = database.buffers[eng_buffer_id];
                {
                    eng_buffer.opengl = create(agl::buffer_tag);
                    storage(eng_buffer.opengl, std::span(mesh.indices));
                }
                auto eng_buffer_view_id = size(database.buffer_views);
                auto& eng_buffer_view = database.buffer_views[eng_buffer_view_id];
                {
                    eng_buffer_view.buffer = eng_buffer_id;
                    eng_buffer_view.byte_length = agl::Size<GLint>(
                        sizeof(tinyobj::index_t) * size(mesh.indices));
                    eng_buffer_view.byte_stride = agl::Stride<GLsizei>(
                        sizeof(tinyobj::index_t));
                }
                auto eng_accessor_id = size(database.accessors);
                auto& eng_accessor = database.accessors[eng_accessor_id];
                {
                    eng_accessor.buffer_view = eng_buffer_view_id;
                    
                }
            }
        }
    }

    // Loop over shapes
    for (size_t s = 0; s < shapes.size(); s++) {
        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);

            // Loop over vertices in the face.
            for (size_t v = 0; v < fv; v++) {
            // access to vertex
            tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

            tinyobj::real_t vx = attrib.vertices[3*size_t(idx.vertex_index)+0];
            tinyobj::real_t vy = attrib.vertices[3*size_t(idx.vertex_index)+1];
            tinyobj::real_t vz = attrib.vertices[3*size_t(idx.vertex_index)+2];

            // Check if `normal_index` is zero or positive. negative = no normal data
            if (idx.normal_index >= 0) {
                tinyobj::real_t nx = attrib.normals[3*size_t(idx.normal_index)+0];
                tinyobj::real_t ny = attrib.normals[3*size_t(idx.normal_index)+1];
                tinyobj::real_t nz = attrib.normals[3*size_t(idx.normal_index)+2];
            }

            // Check if `texcoord_index` is zero or positive. negative = no texcoord data
            if (idx.texcoord_index >= 0) {
                tinyobj::real_t tx = attrib.texcoords[2*size_t(idx.texcoord_index)+0];
                tinyobj::real_t ty = attrib.texcoords[2*size_t(idx.texcoord_index)+1];
            }
            // Optional: vertex colors
            // tinyobj::real_t red   = attrib.colors[3*size_t(idx.vertex_index)+0];
            // tinyobj::real_t green = attrib.colors[3*size_t(idx.vertex_index)+1];
            // tinyobj::real_t blue  = attrib.colors[3*size_t(idx.vertex_index)+2];
            }
            index_offset += fv;

            // per-face material
            shapes[s].mesh.material_ids[f];
        }
    }
}

}
