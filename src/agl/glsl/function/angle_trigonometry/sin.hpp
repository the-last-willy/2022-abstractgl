#pragma once

#include "agl/glsl/vec/vec.hpp"

#include <cmath>
#include <concepts>

namespace agl {

template<std::floating_point FP> constexpr
FP sin(FP fp) {
    return std::sin(fp);
}

template<typename Type, std::size_t Size> constexpr
Vec<Type, Size> sin(const Vec<Type, Size>& v) {
    auto c = Vec<Type, Size>();
    for(std::size_t i = 0; i < Size; ++i) {
        c[i] = sin(v[i]);
    }
    return c;
}

}
