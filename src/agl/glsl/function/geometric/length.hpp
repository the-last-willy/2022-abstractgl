#pragma once

#include "dot.hpp"

#include "agl/glsl/vec/vec.hpp"

#include <cmath>

namespace agl {

template<std::size_t N>
float length(Vec<float, N> v) {
    return std::sqrt(dot(v, v));
}

}
