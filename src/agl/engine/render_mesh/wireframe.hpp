#pragma once

#include "agl/engine/accessor/all.hpp"
#include "agl/engine/triangle_mesh/all.hpp"
#include "agl/engine/material.hpp"
#include "agl/engine/mesh.hpp"

namespace agl::engine {

inline
eng::Mesh wireframe(const TriangleMesh& tm) {
    (void) tm;
    auto m = eng::Mesh();
    // auto& p = *(m.primitives.emplace_back(std::make_shared<eng::Primitive>()));
    // {
    //     p.draw_mode = agl::DrawMode::lines;
    //     p.draw_type = agl::DrawType::unsigned_int;
    // }
    // { // Indices.
    //     if(tm.topology.vertex_per_face == 3) {
    //         auto indices = std::vector<uint32_t>();
    //         for(uint32_t fi = 0; fi < face_count(tm); ++fi) {
    //             auto&& f = triangle(tm, fi);
    //             for(uint32_t fvi = 0; fvi < vertex_count(f); ++fvi) {
    //                 indices.push_back(index(vertex(f, fvi)));
    //             }
    //         }
    //         p.indices = agl::engine::accessor(std::span(indices));
    //         p.primitive_count = agl::Count<GLsizei>(
    //             static_cast<GLsizei>(size(indices)));
    //     } else {
    //         throw std::logic_error("Not implemented");
    //     }
    // }
    return m;
}

}
