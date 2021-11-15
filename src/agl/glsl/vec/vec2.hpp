#pragma once

#include "vec.hpp"

namespace agl {

using Vec2 = Vec<GLfloat, 2>;

constexpr
auto vec2(float e0, float e1) noexcept {
    return Vec<float, 2>{e0, e1};
}

constexpr
auto vec2(float f) {
    return vec2(f, f);
}

}
