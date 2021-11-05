#pragma once

#include "bounding_box.hpp"
#include "max.hpp"
#include "min.hpp"

#include <range/v3/view/iota.hpp>
#include <range/v3/view/transform.hpp>

namespace agl::engine {

inline
auto corners(const BoundingBox& bb) {
    return ranges::views::ints(0, 8)
    | ranges::views::transform([&bb](int i) {
        return agl::vec3(
            (i / 4 % 2 == 0) ? min(bb)[0] : max(bb)[0],
            (i / 2 % 2 == 0) ? min(bb)[1] : max(bb)[1],
            (i % 2 == 0) ? min(bb)[2] : max(bb)[2]); });
}

}
