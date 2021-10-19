#pragma once

#include "agl/engine/accessor/all.hpp"
#include "agl/engine/triangle_mesh/all.hpp"
#include "agl/engine/material.hpp"
#include "agl/engine/mesh.hpp"

#include "agl/geometry/all.hpp"

namespace agl::engine {

inline
auto render_mesh(agl::engine::TriangleMesh& tm, std::vector<std::shared_ptr<eng::Material>> materials = {}) {
    auto m = eng::Mesh();
    auto indices = std::vector<uint32_t>();
    for(uint32_t i = 0; i < vertex_count(tm);) {
        auto& p = *m.primitives.emplace_back(std::make_shared<eng::Primitive>());
        {
            p.draw_type = agl::DrawType::unsigned_int;

            if(tm.vertex_per_face == 3) {
                p.draw_mode = agl::DrawMode::triangles;
            } else if(tm.vertex_per_face == 1) {
                p.draw_mode = agl::DrawMode::points;
            }
            
            p.primitive_count = agl::Count<GLsizei>(
                static_cast<GLsizei>(size(tm.indices)));
            if(not empty(tm.positions)) {
                p.attributes["v"] = accessor(std::span(tm.positions));
            }
        }

        auto material_group = uint32_t(0);
        if(not empty(tm.material_ids)) {
            material_group = tm.material_ids[i];
            p.material = materials[material_group];
        }
        

        for(; i < vertex_count(tm); ++i) {
            if(not empty(tm.material_ids)) {
                if(material_group != tm.material_ids[i]) {
                    break;
                }
            }
            indices.push_back(tm.indices[i]);
        }
        p.indices = accessor(std::span(indices));
        indices.clear();
    }
    return m;
}

}
