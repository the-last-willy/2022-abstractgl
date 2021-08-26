#pragma once

#include "addition_operator.hpp"
#include "dot.hpp"
#include "multiplication_operator.hpp"

#include "quaternion.hpp"

#include <cmath>

namespace agl {

template<typename T>
auto slerp(const Quaternion<T>& lq, const Quaternion<T>& rq, T t) {
    auto theta = std::acos(dot(lq, rq));
    auto sin_theta = std::sin(theta);
    return std::sin((1. - t) * theta) / sin_theta * lq
    + std::sin(t * theta) / sin_theta * rq;
}

}
