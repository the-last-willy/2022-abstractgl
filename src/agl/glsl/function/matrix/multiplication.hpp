#pragma once

#include "agl/glsl/mat/mat.hpp"
#include "agl/glsl/vec/vec.hpp"

namespace agl {

template<typename Type, std::size_t I, std::size_t J> constexpr
auto operator*(Type lt, const Mat<Type, I, J>& rm) {
    auto m = Mat<Type, I, J>();
    for(std::size_t i = 0; i < I; ++i)
    for(std::size_t j = 0; j < J; ++j) {
        m[i][j] += lt * rm[i][j];
    }
    return m;
}

template<typename Type, std::size_t I, std::size_t J, std::size_t K> constexpr
auto operator*(const Mat<Type, I, J>& lm , const Mat<Type, K, I>& rm) {
    auto m = Mat<Type, K, J>();
    for(std::size_t k = 0; k < K; ++k)
    for(std::size_t i = 0; i < I; ++i)
    for(std::size_t j = 0; j < J; ++j) {
        m[k][j] += lm[i][j] * rm[k][i];
    }
    return m;
}

template<typename Type, std::size_t I, std::size_t J> constexpr
auto operator*(const Mat<Type, I, J>& lm , const Vec<Type, I>& rv) {
    auto r = Vec<Type, J>();
    for(std::size_t j = 0; j < J; ++j)
    for(std::size_t i = 0; i < I; ++i) {
        r[j] += lm[i][j] * rv[i];
    }
    return r;
}

}
