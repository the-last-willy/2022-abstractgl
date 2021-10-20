#pragma once

#include "topology/mesh/create_face.hpp"
#include "mesh.hpp"
#include "topology.hpp"

namespace agl::engine {

inline
MutableFaceProxy create_face(TriangleMesh& tm, uint32_t vertex_count) {
    return MutableFaceProxy(
        tm,
        create_face(topology(tm), vertex_count));
}

}
