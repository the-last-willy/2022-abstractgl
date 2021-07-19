#pragma once

#include "agl/glsl/vec/vec.hpp"

namespace agl {

template<typename T, std::size_t N> constexpr
Vec<T, N> operator-(Vec<T, N> v) {
    auto r = Vec<T, N>();
    for(std::size_t i = 0; i < N; ++i) {
        r[i] = -v[i];
    }
    return r;
}

}
