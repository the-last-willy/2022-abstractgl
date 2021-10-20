#pragma once

#include "geometry.hpp"

namespace agl::engine {

inline
uint32_t vertex_count(const Geometry& g) {
    return g.vertex_count;
}

inline
uint32_t create_vertex(Geometry& g) {
    g.vertex_material_ids.emplace_back(0);
    g.vertex_normals.emplace_back();
    g.vertex_positions.emplace_back();
    g.vertex_texcoords.emplace_back();
    g.vertex_count += 1;
    return g.vertex_count - 1;
}

}
