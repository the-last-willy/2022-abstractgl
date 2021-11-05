#pragma once

#include "mesh.hpp"
#include "topology.hpp"

namespace agl::engine {

inline
uint32_t vertex_count(const TriangleMesh& tm) {
    return vertex_count(topology(tm));
}

}
