#pragma once

#include "agl/engine/triangle_mesh/mesh/mesh.hpp"

namespace agl::engine {

struct MutableVertexProxy {
    TriangleMesh* mesh = nullptr;
    uint32_t index = 0;

    MutableVertexProxy() = default;

    MutableVertexProxy(TriangleMesh* tm, uint32_t i) 
        : mesh(tm)
        , index(i)
    {}

    MutableVertexProxy(TriangleMesh& tm, uint32_t i) 
        : mesh(&tm)
        , index(i)
    {}
};

struct ConstVertexProxy {
    const TriangleMesh* mesh = nullptr;
    uint32_t index = 0;

    ConstVertexProxy() = default;

    ConstVertexProxy(const TriangleMesh* tm, uint32_t i) 
        : mesh(tm)
        , index(i)
    {}

    ConstVertexProxy(const TriangleMesh& tm, uint32_t i) 
        : ConstVertexProxy(&tm, i)
    {}

    ConstVertexProxy(MutableVertexProxy mtp)
        : ConstVertexProxy(*mtp.mesh, mtp.index)
    {}
};

}
