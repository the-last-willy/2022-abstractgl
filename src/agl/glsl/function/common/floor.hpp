#pragma once

#include "agl/glsl/vec/vec.hpp"

#include <cmath>
#include <concepts>

namespace agl {

template<std::floating_point FP> constexpr
FP floor(FP fp) {
    return std::floor(fp);
}

template<typename Type, std::size_t Size> constexpr
Vec<Type, Size> floor(const Vec<Type, Size>& v) {
    auto f = Vec<Type, Size>();
    for(std::size_t i = 0; i < Size; ++i) {
        f[i] = floor(v[i]);
    }
    return f;
}

}
