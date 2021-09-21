#pragma once

#include "bounding_box.hpp"
#include "corners.hpp"

namespace agl::engine {

inline
bool are_intersecting(const BoundingBox& bb0, const BoundingBox bb1) {
    auto bb1_to_bb0 = mat(bb0) * inverse(mat(bb1.transform));
    { // Test bb1 in bb0 space.
        auto minh = bb1_to_bb0 * vec4(bb1.min, 1.f);
        auto min = minh.xyz() / minh[3];
        auto maxh = bb1_to_bb0 * vec4(bb1.max, 1.f);
        auto max = maxh.xyz() / maxh[3];
        for(auto c : corners(bb1)) {
            auto h = bb1_to_bb0 * vec4(c, 1.f);
            auto nh = h.xyz() / bh[3];
        }
    }
    { // Test bb0 in bb1 space.

    }
}

}
