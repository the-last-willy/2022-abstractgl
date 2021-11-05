#pragma once

#include "bounding_box.hpp"

namespace agl::engine {

inline
auto max(const BoundingBox& bb) {
    return upper_bound(bb.aabb);
}

}
