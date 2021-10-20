#pragma once

#include "mesh.hpp"

namespace agl::engine {

inline
const Geometry& geometry(const TriangleMesh& tm) {
    return tm.geometry;
}

inline
Geometry& geometry(TriangleMesh& tm) {
    return tm.geometry;
}

}
