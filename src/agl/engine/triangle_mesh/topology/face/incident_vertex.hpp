#pragma once

#include "topology.hpp"

namespace agl::engine {

inline
uint32_t incident_vertex(const FaceTopology& t, uint32_t i) {
    return t.incident_vertices[i];
}

}

