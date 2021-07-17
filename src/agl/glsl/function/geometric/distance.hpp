#pragma once

#include "length.hpp"

#include "agl/glsl/vec/vec.hpp"

namespace agl {

template<std::size_t N>
float distance(Vec<float, N> lv, Vec<float, N> rv) {
    return length(lv - rv);
}

}
