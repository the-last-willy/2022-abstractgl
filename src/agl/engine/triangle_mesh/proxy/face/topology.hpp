#pragma once

#include "mesh/topology.hpp"
#include "index.hpp"
#include "mesh.hpp"
#include "proxy.hpp"

namespace agl::engine {

inline
const FaceTopology& topology(ConstFaceProxy ctp) {
    return topology(mesh(ctp)).faces[index(ctp)];
}

inline
FaceTopology& topology(MutableFaceProxy mtp) {
    return topology(mesh(mtp)).faces[index(mtp)];
}

}
