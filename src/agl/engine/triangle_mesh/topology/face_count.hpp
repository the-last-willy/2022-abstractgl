#pragma once

#include "topology.hpp"
#include "vertex_count.hpp"

namespace agl::engine {

inline
uint32_t face_count(const Topology& t) {
    return vertex_count(t) / t.vertex_per_face;
}

}
