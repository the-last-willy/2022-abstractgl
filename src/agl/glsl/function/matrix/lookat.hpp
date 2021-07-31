#pragma once

#include "agl/glsl/function/geometric/cross.hpp"
#include "agl/glsl/function/geometric/normalize.hpp"
#include "agl/glsl/function/vector/perpendicular.hpp"
#include "agl/glsl/mat/mat4.hpp"
#include "agl/glsl/vec/vec3.hpp"

namespace agl {

inline
agl::Mat4 lookat(agl::Vec3 dir) {
    auto p = agl::normalize(perpendicular(dir));
    return agl::mat4(
        agl::vec4(p, 0.f),
        agl::vec4(dir, 0.f),
        agl::vec4(agl::cross(p, dir), 0.f),
        agl::vec4(0.f, 0.f, 0.f, 1.f));
}

}
