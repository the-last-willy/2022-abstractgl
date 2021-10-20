#pragma once

#include "topology/face/incident_vertex_count.hpp"
#include "proxy.hpp"
#include "topology.hpp"

namespace agl::engine {

inline
uint32_t incident_vertex_count(ConstFaceProxy ctp) {
    return incident_vertex_count(topology(ctp));
}

}
