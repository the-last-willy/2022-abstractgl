#pragma once

#include "agl/engine/accessor/all.hpp"
#include "agl/engine/triangle_mesh/all.hpp"
#include "agl/engine/material.hpp"
#include "agl/engine/mesh.hpp"

namespace agl::engine {

// CONVERT IT TO ANOTHER FACE MESH INSTEAD ?
// AND THEN THAT ONE TO A RENDER MESH.
inline
eng::Mesh wireframe(const TriangleMesh& tm) {
    auto m = eng::Mesh();
    auto positions = std::make_shared<eng::Accessor>(
        agl::engine::accessor(std::span(geometry(tm).vertex_positions)));
    auto& p = *(m.primitives.emplace_back(std::make_shared<eng::Primitive>()));
    {
        p.attributes["position"] = positions;
        p.draw_mode = agl::DrawMode::lines;
        p.draw_type = agl::DrawType::unsigned_int;
    }
    { // Indices.
        auto indices = std::vector<unsigned>();
        for(uint32_t fi = 0; fi < face_count(tm); ++fi) {
            auto f = face(tm, fi);
            for(uint32_t i = 0; i < incident_vertex_count(f); ++i) {
                indices.push_back(index(incident_vertex(f, i)));
            }
        }
        p.indices = std::make_shared<eng::Accessor>(
            agl::engine::accessor(std::span(indices)));
        p.primitive_count = agl::Count<GLsizei>(
            static_cast<GLsizei>(size(indices)));
    }
    return m;
}

}
