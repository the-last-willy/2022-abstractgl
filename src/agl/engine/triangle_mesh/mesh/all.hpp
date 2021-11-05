#pragma once

#include "proxy/all.hpp"
#include "topology/mesh/face_count.hpp"
#include "topology/mesh/vertex_count.hpp"
#include "bounding_box.hpp"
#include "create_face.hpp"
#include "create_vertex.hpp"
#include "geometry.hpp"
#include "mesh.hpp"
#include "topology.hpp"
#include "vertex_count.hpp"

namespace agl::engine {

inline
uint32_t face_count(const TriangleMesh& tm) {
    return face_count(topology(tm));
}

inline
ConstVertexProxy vertex(const TriangleMesh& m, uint32_t i) {
    return ConstVertexProxy(m, i);
}

inline
MutableVertexProxy vertex(TriangleMesh& m, uint32_t i) {
    return MutableVertexProxy(m, i);
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
std::optional<Hit> intersection(const Ray& r, ConstFaceProxy ctp) {
    auto e1 = position(incident_vertex(ctp, 1)) - position(incident_vertex(ctp, 0));
    auto e2 = position(incident_vertex(ctp, 2)) - position(incident_vertex(ctp, 0));

    auto pvec = cross(r.direction, e2);
    auto det = dot(e1, pvec);
    
    auto inv_det = 1 / det;
    auto tvec = r.position - position(incident_vertex(ctp, 0));
    
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
