#pragma once

#include "agl/glsl/mat/mat4.hpp"

#include <cmath>

namespace agl {

inline
auto rotation_x(float radians) {
    auto c = std::cos(radians);
    auto s = std::sin(radians);
    // 2D rotation matrix.
    // | c | -s |
    // | s |  c |
    // 3D rotation matrix.
    // | 1 | 0 |  0 | 0 |
    // | 0 | c | -s | 0 |
    // | 0 | s |  c | 0 |
    // | 0 | 0 |  0 | 1 |
    return mat4(
        1,  0, 0, 0,
        0,  c, s, 0,
        0, -s, c, 0,
        0,  0, 0, 1);
}

}
