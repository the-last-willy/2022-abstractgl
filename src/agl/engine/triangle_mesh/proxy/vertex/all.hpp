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
agl::Vec3 color(ConstVertexProxy cvp) {
    return mesh(cvp).geometry.vertex_colors[index(cvp)];
}

inline
agl::Vec3& color(MutableVertexProxy mvp) {
    return mesh(mvp).geometry.vertex_colors[index(mvp)];
}

inline
uint32_t material_id(ConstVertexProxy cvp) {
    return mesh(cvp).geometry.vertex_material_ids[index(cvp)];
}

inline
uint32_t& material_id(MutableVertexProxy mvp) {
    return mesh(mvp).geometry.vertex_material_ids[index(mvp)];
}

inline
agl::Vec3 normal(ConstVertexProxy cvp) {
    return mesh(cvp).geometry.vertex_normals[index(cvp)];
}

inline
agl::Vec3& normal(MutableVertexProxy mvp) {
    return mesh(mvp).geometry.vertex_normals[index(mvp)];
}

inline
agl::Vec3 position(ConstVertexProxy cvp) {
    return mesh(cvp).geometry.vertex_positions[index(cvp)];
}

inline
agl::Vec3& position(MutableVertexProxy mvp) {
    return mesh(mvp).geometry.vertex_positions[index(mvp)];
}

inline
agl::Vec2 texcoords(ConstVertexProxy cvp) {
    return mesh(cvp).geometry.vertex_texcoords[index(cvp)];
}

inline
agl::Vec2& texcoords(MutableVertexProxy mvp) {
    return mesh(mvp).geometry.vertex_texcoords[index(mvp)];
}

}
