#pragma once

#include "agl/glsl/vec/vec.hpp"

namespace agl {

template<typename T, std::size_t N> constexpr
float cross(Vec<T, N> lv, Vec<T, N> rv) {
    auto c = float(0);
    for(std::size_t i = 0; i < N; ++i) {
        c += lv[i] * rv[(i + 1) % N] - lv[(i + 1) % N] * rv[i];
    }
    return c;
}

}
