#pragma once

#include "agl/opengl/all.hpp"

#include <optional>
#include <vector>

namespace agl::mesh::triangle {

struct Mesh {
    std::vector<uint32_t> indices;

    std::vector<agl::Vec3> normals;
    std::vector<agl::Vec3> positions;
    std::vector<agl::Vec2> texcoords;
};

struct VertexProxy {
    Mesh* mesh;
    uint32_t index;
};

inline
VertexProxy vertex(Mesh& m, uint32_t i) {
    return VertexProxy(&m, i);
}

inline
agl::Vec3 position(VertexProxy vp) {
    return vp.mesh->positions[vp.index];
}

struct TriangleProxy {
    Mesh* mesh;
    uint32_t index;
};

inline
TriangleProxy triangle(Mesh& m, uint32_t i) {
    return TriangleProxy(&m, i);
}

inline
VertexProxy vertex(TriangleProxy tp, uint32_t i) {
    return vertex(*tp.mesh, tp.mesh->indices[3 * tp.index + i]);
}

struct Ray {
    agl::Vec3 position;
    agl::Vec3 direction;
};

struct Hit {
    float ray;
    std::array<float, 3> triangle;
};

inline
std::optional<Hit> intersection(const Ray& r, TriangleProxy tp) {
    auto e1 = position(vertex(tp, 1)) - position(vertex(tp, 0));
    auto e2 = position(vertex(tp, 2)) - position(vertex(tp, 0));

    auto pvec = cross(r.direction, e2);
    auto det = dot(e1, pvec);
    
    auto inv_det = 1 / det;
    auto tvec = r.position - position(vertex(tp, 0));
    
    auto u = dot(tvec, pvec) * inv_det;
    if(u < 0 || u > 1) return std::nullopt;
    
    auto qvec= cross(tvec, e1);
    auto v = dot(r.direction, qvec) * inv_det;
    if(v < 0 || u + v > 1) return std::nullopt;
    
    auto t = dot(e2, qvec) * inv_det;
    if(t < 0) return std::nullopt;
    
    return Hit(t, {u, v, 1.f - u - v});
}

}
