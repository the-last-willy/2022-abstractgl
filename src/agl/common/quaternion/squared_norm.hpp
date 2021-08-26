#pragma once

#include "quaternion.hpp"

#include "agl/glsl/function/geometric/dot.hpp"

namespace agl {

template<typename T> constexpr
auto squared_norm(const Quaternion<T>& q) {
    return q.real * q.real + dot(q.pure, q.pure);
}

}
