#pragma once

#include "proxy/all.hpp"
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

inline
uint32_t vertex_count(const TriangleMesh& tm) {
    // return vertex_count(topology(tm));
    return static_cast<uint32_t>(size(tm.indices));
}

inline
uint32_t face_count(const TriangleMesh& tm) {
    // return face_count(topology(tm));
    return static_cast<uint32_t>(size(tm.indices) / tm.vertex_per_face);

}

inline
ConstTriangleProxy triangle(const TriangleMesh& m, uint32_t i) {
    return ConstTriangleProxy(m, i);
}

inline
MutableTriangleProxy triangle(TriangleMesh& m, uint32_t i) {
    return MutableTriangleProxy(m, i);
}

inline
ConstVertexProxy create_vertex(TriangleMesh& m) {
    return ConstVertexProxy(
        m,
        create_vertex(m.geometry));
}

struct Ray {
    agl::Vec3 position;
    agl::Vec3 direction;
};

struct Hit {
    float ray;
    std::array<float, 3> triangle;
    agl::Vec3 position;
};

inline
std::optional<Hit> intersection(const Ray& r, ConstTriangleProxy ctp) {
    auto e1 = position(vertex(ctp, 1)) - position(vertex(ctp, 0));
    auto e2 = position(vertex(ctp, 2)) - position(vertex(ctp, 0));

    auto pvec = cross(r.direction, e2);
    auto det = dot(e1, pvec);
    
    auto inv_det = 1 / det;
    auto tvec = r.position - position(vertex(ctp, 0));
    
    auto u = dot(tvec, pvec) * inv_det;
    if(u < 0 || u > 1) return std::nullopt;
    
    auto qvec= cross(tvec, e1);
    auto v = dot(r.direction, qvec) * inv_det;
    if(v < 0 || u + v > 1) return std::nullopt;
    
    auto t = dot(e2, qvec) * inv_det;
    if(t < 0) return std::nullopt;
    
    return Hit(t, {u, v, 1.f - u - v}, r.position + t * r.direction);
}

}
