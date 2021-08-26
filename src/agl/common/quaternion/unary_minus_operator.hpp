#pragma once

#include "quaternion.hpp"

#include "agl/glsl/function/vector/subtraction.hpp"

namespace agl {

template<typename Q> constexpr
auto operator-(const Quaternion<Q>& q) {
    return Quaternion<Q>(-q.real, -q.pure);
}

}
