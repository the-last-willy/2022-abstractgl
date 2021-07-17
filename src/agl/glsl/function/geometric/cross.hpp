#pragma once

#include "agl/glsl/vec/vec.hpp"

namespace agl {

constexpr
float cross(Vec<float, 3> lv, Vec<float, 3> rv) {
    constexpr auto N = 3;
    auto c = float(0);
    for(std::size_t i = 0; i < N; ++i) {
        c += lv[i] * rv[(i + 1) % N] - lv[(i + 1) % N] * rv[i];
    }
    return c;
}

}
