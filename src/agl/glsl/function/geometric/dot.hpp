#pragma once

#include "agl/glsl/vec/vec.hpp"

namespace agl {

template<typename T, std::size_t N> constexpr
float dot(Vec<T, N> lv, Vec<T, N> rv) {
    auto d = float(0);
    for(std::size_t i = 0; i < N; ++i) {
        d += lv[i] * rv[i];
    }
    return d;
}

}
