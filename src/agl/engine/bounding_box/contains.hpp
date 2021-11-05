#pragma once

#include "bounding_box.hpp"

namespace agl::engine {

inline
bool contains(const BoundingBox& bb, agl::Vec3 v) {
    return v[0] >= min(bb)[0]
    and v[1] >= min(bb)[1]
    and v[2] >= min(bb)[2]
    and v[0] <= max(bb)[0]
    and v[1] <= max(bb)[1]
    and v[2] <= max(bb)[2];
}

}
