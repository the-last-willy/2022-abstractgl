#pragma once

#include "agl/glsl/function/geometric/cross.hpp"
#include "agl/glsl/vec/vec3.hpp"

namespace agl {

constexpr
auto perpendicular(Vec3 v) {
    // return vec3(
    //     v[1] - v[2],
    //     v[2] - v[0],
    //     v[0] - v[1]);
    if(v[0] == 1.f) {
        return cross(v, vec3(0.f, 1.f, 0.f));
    } else {
        return cross(v, vec3(1.f, 0.f, 0.f));
    }
}

}
