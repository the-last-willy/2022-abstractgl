#pragma once

#include "quaternion.hpp"

#include "agl/glsl/function/vector/subtraction.hpp"

namespace agl {

template<typename T> constexpr
auto conjugate(const Quaternion<T>& q) {
    return Quaternion<T>(q.real, -q.pure);
}

}
