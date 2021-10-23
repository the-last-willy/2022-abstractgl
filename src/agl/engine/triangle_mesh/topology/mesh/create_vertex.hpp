#pragma once

#include "proxy/vertex/proxy.hpp"
#include "topology.hpp"

namespace agl::engine {

inline
void create_vertex(MeshTopology& t) {
    t.vertex_count += 1;
}

}
