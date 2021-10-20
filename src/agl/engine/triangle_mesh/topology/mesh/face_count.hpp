#pragma once

#include "topology.hpp"

namespace agl::engine {

inline
uint32_t face_count(const Topology& t) {
    return static_cast<uint32_t>(size(t.faces));
}

}
