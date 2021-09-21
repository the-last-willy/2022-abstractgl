#pragma once

#include "bounding_box.hpp"
#include "corners.hpp"

namespace agl::engine {

inline
bool are_intersecting(const BoundingBox& bb0, const BoundingBox bb1) {
    { // Test bb1 in bb0 space.
        auto bb1_to_bb0 = mat4(bb0.transform) * inverse(mat4(bb1.transform));
        auto counts = std::array<int, 6>();
        for(auto c : corners(bb1)) {
            // Homogeneous space.
            auto h = bb1_to_bb0 * vec4(c, 1.f);
            // Normalized homogeneous space.
            auto nh = h.xyz() / h[3];
            // Counts corners on each side.
            counts[0] += nh[0] < bb0.min[0];
            counts[1] += nh[0] > bb0.max[0];
            counts[2] += nh[1] < bb0.min[1];
            counts[3] += nh[1] > bb0.max[1];
            counts[4] += nh[2] < bb0.min[2];
            counts[5] += nh[2] > bb0.max[2];
        }
        for(auto c : counts) {
            if(c == 6) {
                return false;
            }
        }
    }
    { // Test bb0 in bb1 space.
        auto bb0_to_bb1 = mat4(bb1.transform) * inverse(mat4(bb0.transform));
        auto counts = std::array<int, 6>();
        for(auto c : corners(bb0)) {
            // Homogeneous space.
            auto h = bb0_to_bb1 * vec4(c, 1.f);
            // Normalized homogeneous space.
            auto nh = h.xyz() / h[3];
            // Counts corners on each side.
            counts[0] += nh[0] < bb1.min[0];
            counts[1] += nh[0] > bb1.max[0];
            counts[2] += nh[1] < bb1.min[1];
            counts[3] += nh[1] > bb1.max[1];
            counts[4] += nh[2] < bb1.min[2];
            counts[5] += nh[2] > bb1.max[2];
        }
        for(auto c : counts) {
            if(c == 6) {
                return false;
            }
        }
    }
    return true;
}

}
