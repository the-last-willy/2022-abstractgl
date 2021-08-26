#pragma once

#include "conjugate.hpp"
#include "division_operator.hpp"
#include "squared_norm.hpp"

#include "quaternion.hpp"

namespace agl {

template<typename T> constexpr
auto inversed(const Quaternion<T>& q) {
    return conjugate(q) / squared_norm(q);
}

}
