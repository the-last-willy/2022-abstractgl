#pragma once

#include "vec.hpp"

namespace agl {

using Vec3 = Vec<GLfloat, 3>;

constexpr
auto vec3(float e0, float e1, float e2) noexcept {
    return Vec<float, 3>{e0, e1, e2};
}

constexpr
auto vec3(Vec<float, 2> v01, float e2) noexcept {
    return vec3(v01[0], v01[1], e2);
}

}
