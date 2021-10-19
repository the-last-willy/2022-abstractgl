#pragma once

#include "proxy.hpp"

namespace agl::engine {

inline
uint32_t index(ConstVertexProxy cvp) {
    return cvp.index;
}

inline
const TriangleMesh& mesh(ConstVertexProxy cvp) {
    return *cvp.mesh;
}

inline
TriangleMesh& mesh(MutableVertexProxy mvp) {
    return *mvp.mesh;
}

inline
const Geometry& geometry(ConstVertexProxy cvp) {
    return mesh(cvp).geometry;
}

inline
Geometry& geometry(MutableVertexProxy mvp) {
    return mesh(mvp).geometry;
}

inline
agl::Vec3 position(ConstVertexProxy cvp) {
    return mesh(cvp).geometry.vertex_positions[index(cvp)];
}

inline
agl::Vec3& position(MutableVertexProxy mvp) {
    return mesh(mvp).geometry.vertex_positions[index(mvp)];
}

}
