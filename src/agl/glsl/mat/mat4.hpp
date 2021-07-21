#pragma once

#include "mat.hpp"

#include "agl/tag/identity.hpp"

namespace agl {

using Mat4 = Mat<GLfloat, 4, 4>;

constexpr
auto mat4(
    float e00, float e01, float e02, float e03,
    float e10, float e11, float e12, float e13,
    float e20, float e21, float e22, float e23,
    float e30, float e31, float e32, float e33)
{
    return Mat4{
        e00, e01, e02, e03,
        e10, e11, e12, e13,
        e20, e21, e22, e23,
        e30, e31, e32, e33};
}

constexpr
auto mat4(IdentityTag)
{
    return Mat4{
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1};
}

}
