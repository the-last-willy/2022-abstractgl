#pragma once

#include "bounding_box.hpp"

namespace agl::engine {

inline
auto transform(const BoundingBox& bb) {
    return bb.transform;
}

}
