#pragma once

#include "mesh.hpp"

namespace agl::engine {

inline
const Topology& topology(const TriangleMesh& tm) {
    return tm.topology;
}

inline
Topology& topology(TriangleMesh& tm) {
    return tm.topology;
}

}
