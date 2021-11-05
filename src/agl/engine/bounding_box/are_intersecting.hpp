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
            counts[0] += nh[0] < min(bb0)[0];
            counts[1] += nh[0] > max(bb0)[0];
            counts[2] += nh[1] < min(bb0)[1];
            counts[3] += nh[1] > max(bb0)[1];
            counts[4] += nh[2] < min(bb0)[2];
            counts[5] += nh[2] > max(bb0)[2];
        }
        for(auto c : counts) {
            if(c == 8) {
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
            counts[0] += nh[0] < min(bb1)[0];
            counts[1] += nh[0] > max(bb1)[0];
            counts[2] += nh[1] < min(bb1)[1];
            counts[3] += nh[1] > max(bb1)[1];
            counts[4] += nh[2] < min(bb1)[2];
            counts[5] += nh[2] > max(bb1)[2];
        }
        for(auto c : counts) {
            if(c == 8) {
                return false;
            }
        }
    }
    return true;
}

}
