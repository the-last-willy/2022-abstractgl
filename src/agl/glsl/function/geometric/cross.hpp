#pragma once

#include "agl/glsl/vec/vec2.hpp"
#include "agl/glsl/vec/vec3.hpp"

namespace agl {

constexpr
float cross(Vec2 lv, Vec2 rv) {
    return lv[0] * rv[1] - lv[1] * rv[0];
}

constexpr
Vec3 cross(Vec3 lv, Vec3 rv) {
    return agl::vec3(
        lv[1] * rv[2] - lv[2] * rv[1],
        lv[2] * rv[0] - lv[0] * rv[2],
        lv[0] * rv[1] - lv[1] * rv[0]);
}

}
