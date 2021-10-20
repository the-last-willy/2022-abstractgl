#pragma once

#include "topology.hpp"

namespace agl::engine {

inline
uint32_t incident_vertex_count(const FaceTopology& t) {
    return t.incident_vertex_count;
}

}

