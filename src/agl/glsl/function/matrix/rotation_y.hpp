#pragma once

#include "agl/glsl/mat/mat4.hpp"

#include <cmath>

namespace agl {

inline
auto rotation_y(float radians) {
    auto c = std::cos(radians);
    auto s = std::sin(radians);
    // 2D rotation matrix.
    // | c | -s |
    // | s |  c |
    // 3D rotation matrix.
    // |  c | 0 | s | 0 |
    // |  0 | 1 | 0 | 0 |
    // | -s | 0 | c | 0 |
    // |  0 | 0 | 0 | 1 |
    return mat4(
         c, 0, s, 0,
         0, 1, 0, 0,
        -s, 0, c, 0,
         0, 0, 0, 1);
}

}
