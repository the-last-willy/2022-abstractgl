#pragma once

#include "vertex/proxy.hpp"
#include "proxy.hpp"

namespace agl::engine {

inline
uint32_t index(ConstTriangleProxy ctp) {
    return ctp.index;
}

inline
const TriangleMesh& mesh(ConstTriangleProxy ctp) {
    return *ctp.mesh;
}

inline
TriangleMesh& mesh(MutableTriangleProxy mtp) {
    return *mtp.mesh;
}

inline
const Topology& topology(ConstTriangleProxy ctp) {
    return mesh(ctp).topology;
}

inline
Topology& topology(MutableTriangleProxy mtp) {
    return mesh(mtp).topology;
}

inline
uint32_t vertex_count(ConstTriangleProxy ctp) {
    return topology(ctp).vertex_per_face;
}

inline
ConstVertexProxy vertex(ConstTriangleProxy ctp, uint32_t i) {
    return ConstVertexProxy(
        mesh(ctp),
        topology(ctp).face_indices[vertex_count(ctp) * index(ctp) + i]);
}

inline
MutableVertexProxy vertex(MutableTriangleProxy mtp, uint32_t i) {
    return MutableVertexProxy(
        mesh(mtp),
        topology(mtp).face_indices[vertex_count(mtp) * index(mtp) + i]);
}

}
