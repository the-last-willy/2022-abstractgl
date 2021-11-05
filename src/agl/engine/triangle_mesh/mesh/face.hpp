#pragma once

#include "mesh.hpp"

namespace agl::engine {

inline
ConstFaceProxy face(const TriangleMesh& m, uint32_t i) {
    return ConstFaceProxy(m, i);
}

inline
MutableFaceProxy face(TriangleMesh& m, uint32_t i) {
    return MutableFaceProxy(m, i);
}

}
