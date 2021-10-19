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
    auto& p = *(m.primitives.emplace_back(std::make_shared<eng::Primitive>()));
    p.draw_type = agl::DrawType::unsigned_int;
    p.indices = accessor(std::span(tm.indices));
    p.primitive_count = agl::Count<GLsizei>(
        static_cast<GLsizei>(size(tm.indices)));
    if(not empty(tm.positions)) {
        p.attributes["v"] = accessor(std::span(tm.positions));
    }
    if(not empty(tm.material_ids) && not empty(materials)) {
        auto mid = tm.material_ids.front();
        if(mid < size(materials)) {
            p.material = materials[mid];
        } else {
            throw std::logic_error("Missing material.");
        }
    }
    return m;
}

}
