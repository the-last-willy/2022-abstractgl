#pragma once

#include "vec.hpp"

namespace agl {

using Vec4 = Vec<GLfloat, 4>;

constexpr
auto vec4(float e0, float e1, float e2, float e3) noexcept {
    return Vec<float, 4>{e0, e1, e2, e3};
}

constexpr
auto vec4(Vec<float, 3> v012, float e3) noexcept {
    return vec4(v012[0], v012[1], v012[2], e3);
}

constexpr
auto vec4(float f) {
    return vec4(f, f, f, f);
}

}
