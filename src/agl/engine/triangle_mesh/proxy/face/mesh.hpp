#pragma once

#include "proxy.hpp"

namespace agl::engine {

inline
const TriangleMesh& mesh(ConstFaceProxy ctp) {
    return *ctp.mesh;
}

inline
TriangleMesh& mesh(MutableFaceProxy mtp) {
    return *mtp.mesh;
}

}
