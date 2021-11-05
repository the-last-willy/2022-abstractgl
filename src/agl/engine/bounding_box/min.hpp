#pragma once

#include "bounding_box.hpp"

namespace agl::engine {

inline
auto min(const BoundingBox& bb) {
    return lower_bound(bb.aabb);
}

}
