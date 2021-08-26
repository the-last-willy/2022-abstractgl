#pragma once

#include "quaternion.hpp"

#include <cmath>

namespace agl {

template<typename T> constexpr
auto power(const Quaternion<T>& q, T exponent) {
    auto theta = std::acos(q.real);
    if(std::abs(q.real) < .9999f) {
        auto real = std::cos(q.real * exponent);
        auto pure = std::sin(q.real * exponent) / std::sin(theta) * q.pure;
        return Quaternion<T>(real, pure);
    } else {
        return q;
    }
}

}
