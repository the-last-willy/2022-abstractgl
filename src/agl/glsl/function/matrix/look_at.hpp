#pragma once

#include "agl/glsl/function/geometric/cross.hpp"
#include "agl/glsl/mat/mat4.hpp"
#include "agl/glsl/vec/vec3.hpp"

namespace agl {

inline
Mat4 look_at(Vec3 fw, Vec3 up) {
    return agl::mat4(
        vec4(cross(up, fw), 0.f),
        vec4(up, 0.f),
        vec4(fw, 0.f),
        vec4(0.f, 0.f, 0.f, 1.f));
}

// inline
// Mat4 look_at(Vec3 dir) {
//     auto p = agl::normalize(perpendicular(dir));
//     return agl::mat4(
//         agl::vec4(p, 0.f),
//         agl::vec4(dir, 0.f),
//         agl::vec4(agl::cross(p, dir), 0.f),
//         agl::vec4(0.f, 0.f, 0.f, 1.f));
// }

}
