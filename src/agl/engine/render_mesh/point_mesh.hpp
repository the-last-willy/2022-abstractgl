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
    auto positions = accessor(std::span(geometry(tm).vertex_positions));
    for(uint32_t vi = 0; vi < vertex_count(tm);) {
        auto& p = *m.primitives.emplace_back(std::make_shared<eng::Primitive>());
        {
            p.attributes["v"] = positions;
            p.draw_mode = agl::DrawMode::points;
            p.draw_type = agl::DrawType::unsigned_int;
        }

        // auto material_group = material_id(incident_vertex(face(tm, f), 0));
        // if(not empty(materials)) {
        //     p.material = materials[material_group];
        // }

        for(; vi < vertex_count(tm); ++vi) {
            auto&& v = vertex(tm, vi);
            indices.push_back(index(v));
        }

        // label:

        // std::cout << "Primitive " << material_group << ": ";
        // for(auto&& i : indices) {
        //     std::cout << i << " ";
        // }
        // std::cout << std::endl;

        p.indices = accessor(std::span(indices));
        p.primitive_count = agl::Count<GLsizei>(
            static_cast<GLsizei>(size(indices)));
        indices.clear();
    }
    return m;
}

}
