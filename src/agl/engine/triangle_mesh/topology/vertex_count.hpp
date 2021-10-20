#pragma once

#include "topology.hpp"

namespace agl::engine {

inline
uint32_t vertex_count(const Topology& t) {
    return static_cast<uint32_t>(size(t.face_indices));
}

}
