#pragma once

#include "agl/engine/accessor/all.hpp"
#include "agl/engine/triangle_mesh/all.hpp"
#include "agl/engine/material.hpp"
#include "agl/engine/mesh.hpp"

#include "agl/geometry/all.hpp"

namespace agl::engine {

// BIG MEMORY LEAK AROUND HERE
inline
auto point_mesh(agl::engine::TriangleMesh& tm, std::vector<std::shared_ptr<eng::Material>>& materials) {
    (void) materials;
    auto m = eng::Mesh();
    auto indices = std::vector<uint32_t>();
    auto colors = std::make_shared<eng::Accessor>(
        accessor(std::span(geometry(tm).vertex_colors)));
    auto normals = std::make_shared<eng::Accessor>(
        accessor(std::span(geometry(tm).vertex_normals)));
    auto positions = std::make_shared<eng::Accessor>(
        accessor(std::span(geometry(tm).vertex_positions)));
    for(uint32_t vi = 0; vi < vertex_count(tm);) {
        auto& p = *m.primitives.emplace_back(std::make_shared<eng::Primitive>());
        {
            p.attributes["color"] = colors;
            p.attributes["v"] = positions;
            p.attributes["vn"] = normals;
            p.draw_mode = agl::DrawMode::points;
            p.draw_type = agl::DrawType::unsigned_int;
        }

        for(; vi < vertex_count(tm); ++vi) {
            auto&& v = vertex(tm, vi);
            indices.push_back(index(v));
        }

        p.indices = std::make_shared<eng::Accessor>(accessor(std::span(indices)));
        p.primitive_count = agl::Count<GLsizei>(
            static_cast<GLsizei>(size(indices)));
        indices.clear();
    }
    return m;
}

}
