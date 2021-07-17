#pragma once

#include "mat.hpp"

namespace agl {

using Mat2 = Mat<GLfloat, 2, 2>;

constexpr
auto mat2(
    float e00, float e01,
    float e10, float e11)
{
    return Mat2{
        e00, e01,
        e10, e11};
}

}
