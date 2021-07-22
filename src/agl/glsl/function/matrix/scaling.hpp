#pragma once

#include "agl/glsl/mat/mat4.hpp"

namespace agl {

constexpr
Mat4 scaling3(float x, float y, float z) {
    return agl::mat4(
          x, 0.f, 0.f, 0.f,
        0.f,   y, 0.f, 0.f,
        0.f, 0.f,   z, 0.f,
        0.f, 0.f, 0.f, 1.f);
}

constexpr
Mat4 scaling3(float s) {
    return scaling3(s, s, s);
}

}
