#pragma once

#include "agl/glsl/vec/vec.hpp"

namespace agl {

template<typename T> constexpr
T min(T t0, T t1) {
    return (t0 < t1) ? t0 : t1;
}

template<typename T, std::size_t N> constexpr
Vec<T, N> min(const Vec<T, N>& v0, const Vec<T, N>& v1) {
    auto m = Vec<T, N>();
    for(std::size_t i = 0; i < size(m); ++i) {
        m[i] = min(v0[i], v1[i]);
    }
    return m;
}

}
