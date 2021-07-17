#pragma once

#include "vec.hpp"

namespace agl {


template<typename T, std::size_t N> constexpr
Vec<T, N> operator/(Vec<T, N> lv, float rf) {
    auto r = Vec<T, N>();
    for(std::size_t i = 0; i < N; ++i) {
        r[i] = lv[i] / rf;
    }
    return r;
}

template<typename T, std::size_t N> constexpr
Vec<T, N> operator/(Vec<T, N> lv, Vec<T, N> rv) {
    auto r = Vec<T, N>();
    for(std::size_t i = 0; i < N; ++i) {
        r[i] = lv[i] / rv[i];
    }
    return r;
}

template<typename T, std::size_t N, typename R> constexpr
Vec<T, N>& operator/=(Vec<T, N>& lv, R r) {
    return lv = lv / r;
}

}
