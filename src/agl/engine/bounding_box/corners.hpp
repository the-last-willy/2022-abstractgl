#pragma once

#include "bounding_box.hpp"

#include <range/v3/view/iota.hpp>
#include <range/v3/view/transform.hpp>

namespace agl::engine {

inline
auto corners(const BoundingBox& bb) {
    return ranges::views::ints(0, 8)
    | ranges::views::transform([&bb](int i) {
        return agl::vec3(
            (i / 4 % 2 == 0) ? bb.min[0] : bb.max[0],
            (i / 2 % 2 == 0) ? bb.min[1] : bb.max[1],
            (i % 2 == 0) ? bb.min[2] : bb.max[2]); });
}

}
