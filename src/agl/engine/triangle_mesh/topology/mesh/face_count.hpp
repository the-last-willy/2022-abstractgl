#pragma once

#include "topology.hpp"

namespace agl::engine {

inline
uint32_t face_count(const MeshTopology& t) {
    return static_cast<uint32_t>(size(t.faces));
}

}
