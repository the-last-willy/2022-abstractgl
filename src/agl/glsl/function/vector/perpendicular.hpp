#pragma once

#include "agl/glsl/vec/vec3.hpp"

namespace agl {

constexpr
auto perpendicular(agl::Vec3 v) {
    return agl::vec3(
        v[1] - v[2],
        v[2] - v[0],
        v[0] - v[1]);
}

}
