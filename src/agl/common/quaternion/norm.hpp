#pragma once

#include "squared_norm.hpp"

#include "quaternion.hpp"

#include "agl/glsl/function/geometric/dot.hpp"

#include <cmath>

namespace agl {

template<typename T>
auto norm(const Quaternion<T>& q) {
    return std::sqrt(squared_norm(q));
}

}
