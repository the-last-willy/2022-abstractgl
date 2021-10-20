#pragma once

#include "topology.hpp"

namespace agl::engine {

inline
uint32_t vertex_count(const Topology& t) {
    return static_cast<uint32_t>(size(t.face_indices));
}

inline
uint32_t face_count(const Topology& t) {
    return vertex_count(t) / t.vertex_per_face;
}

}
