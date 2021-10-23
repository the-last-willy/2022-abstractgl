#pragma once

#include "mesh.hpp"

namespace agl::engine {

inline
const MeshTopology& topology(const TriangleMesh& tm) {
    return tm.topology;
}

inline
MeshTopology& topology(TriangleMesh& tm) {
    return tm.topology;
}

}
