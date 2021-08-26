#pragma once

#include "multiplication_operator.hpp"
#include "quaternion.hpp"

namespace agl {

template<typename T> constexpr
auto operator/(const Quaternion<T>& lq, const T& rt) {
    return Quaternion(lq.real / rt, lq.pure / rt);
}

}
