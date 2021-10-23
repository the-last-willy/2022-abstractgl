#pragma once

#include "topology.hpp"

namespace agl::engine {

inline
uint32_t vertex_count(const MeshTopology& t) {
    return t.vertex_count;
}

}
