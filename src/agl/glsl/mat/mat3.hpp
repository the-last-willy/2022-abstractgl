#pragma once

#include "mat.hpp"

namespace agl {

using Mat3 = Mat<GLfloat, 3, 3>;

constexpr
auto mat3(
    float e00, float e01, float e02,
    float e10, float e11, float e12,
    float e20, float e21, float e22)
{
    return Mat3{
        e00, e01, e02,
        e10, e11, e12,
        e20, e21, e22};
}

}
