#pragma once

#include "bounding_box.hpp"

namespace agl::engine {

inline
bool contains(const BoundingBox& bb, agl::vec3 v) {
    return v[0] >= bb.min[0]
    and v[1] >= bb.min[1]
    and v[2] >= bb.min[2]
    and v[0] <= bb.max[0]
    and v[1] <= bb.max[1]
    and v[2] <= bb.max[2];
}

}
