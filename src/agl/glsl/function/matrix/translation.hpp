#pragma once

#include "agl/glsl/mat/mat4.hpp"
#include "agl/glsl/vec/vec.hpp"

namespace agl {

constexpr
auto translation(GLfloat x, GLfloat y, GLfloat z) {
    return mat4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        x, y, z, 1);
}

constexpr
auto translation(const Vec<GLfloat, 3>& v) {
    return translation(v[0], v[1], v[2]);
}

}
