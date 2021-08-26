#pragma once

#include "squared_norm.hpp"

#include "quaternion.hpp"

#include "agl/glsl/function/geometric/dot.hpp"

#include <cmath>

namespace agl {

template<typename T> constexpr
auto dot(const Quaternion<T>& lq, const Quaternion<T>& rq) {
    return lq.real * rq.real + dot(lq.pure, rq.pure);
}

}
