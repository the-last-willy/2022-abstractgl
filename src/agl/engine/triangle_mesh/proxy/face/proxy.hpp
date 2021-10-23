#pragma once

#include "mesh/mesh.hpp"

namespace agl::engine {

// RENAME INTO FACE INSTEAD

struct MutableFaceProxy {
    MutableFaceProxy() = default;

    MutableFaceProxy(TriangleMesh* tm, uint32_t i) 
        : mesh(tm)
        , index(i)
    {}

    MutableFaceProxy(TriangleMesh& tm, uint32_t i) 
        : MutableFaceProxy(&tm, i)
    {}

    TriangleMesh* mesh = nullptr;;
    uint32_t index = 0;
};

struct ConstFaceProxy {
    ConstFaceProxy() = default;

    ConstFaceProxy(const TriangleMesh* tm, uint32_t i) 
        : mesh(tm)
        , index(i)
    {}

    ConstFaceProxy(const TriangleMesh& tm, uint32_t i) 
        : ConstFaceProxy(&tm, i)
    {}

    ConstFaceProxy(MutableFaceProxy mtp)
        : ConstFaceProxy(*mtp.mesh, mtp.index)
    {}

    const TriangleMesh* mesh = nullptr;;
    uint32_t index = 0;
};

}
