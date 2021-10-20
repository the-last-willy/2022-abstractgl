#pragma once

#include "proxy/vertex/proxy.hpp"
#include "mesh.hpp"

namespace agl::engine {

inline
void create_vertex(Topology& t) {
    t.vertex_count += 1;
}

}
