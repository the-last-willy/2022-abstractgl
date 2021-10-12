#pragma once

#include "agl/engine/accessor/all.hpp"
#include "agl/engine/mesh.hpp"

#include "agl/geometry/all.hpp"

namespace agl::engine {

inline
auto render_mesh(mesh::triangle::Mesh& tm) {
    auto m = eng::Mesh();
    auto& p = *(m.primitives.emplace_back(std::make_shared<eng::Primitive>()));
    p.indices = accessor(std::span(tm.indices));
    if(not empty(tm.positions)) {
        p.attributes["v"] = accessor(std::span(tm.positions));
    }
    return m;
}

}
