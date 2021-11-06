#pragma once

#include "mesh.hpp"
#include "topology.hpp"

namespace agl::engine {

inline
uint32_t face_count(const TriangleMesh& tm) {
    return face_count(topology(tm));
}

}
