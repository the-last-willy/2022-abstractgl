#pragma once

#include "agl/engine/triangle_mesh/mesh/mesh.hpp"

namespace agl::engine {

struct MutableVertexProxy {
    MutableVertexProxy(TriangleMesh& tm, uint32_t i) 
        : mesh(&tm)
        , index(i)
    {}

    TriangleMesh* mesh;
    uint32_t index;
};

struct ConstVertexProxy {
    ConstVertexProxy(const TriangleMesh& tm, uint32_t i) 
        : mesh(&tm)
        , index(i)
    {}

    ConstVertexProxy(MutableVertexProxy mtp)
        : ConstVertexProxy(*mtp.mesh, mtp.index)
    {}

    const TriangleMesh* mesh;
    uint32_t index;
};

}
