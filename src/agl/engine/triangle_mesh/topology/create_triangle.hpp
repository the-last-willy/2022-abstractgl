#pragma once

#include "proxy/vertex/proxy.hpp"
#include "topology.hpp"

namespace agl::engine {

inline
uint32_t create_triangle(Topology& t) {
    t.face_count += 1;
    return 0;
}

}
