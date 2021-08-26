#pragma once

#include "agl/glsl/mat/mat.hpp"

namespace agl {

template<typename T, std::size_t C, std::size_t R> constexpr
auto operator+(const Mat<T, C, R>& lm , const Mat<T, C, R>& rm) {
    auto m = Mat<T, C, R>();
    for(std::size_t c = 0; c < C; ++c)
    for(std::size_t r = 0; r < R; ++r) {
        m[c][r] = lm[c][r] + rm[c][r];
    }
    return m;
}

}
