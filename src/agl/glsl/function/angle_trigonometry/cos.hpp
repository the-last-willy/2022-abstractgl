#pragma once

#include "agl/glsl/vec/vec.hpp"

#include <cmath>
#include <concepts>

namespace agl {

template<std::floating_point FP> constexpr
FP cos(FP fp) {
    return std::cos(fp);
}

template<typename Type, std::size_t Size> constexpr
Vec<Type, Size> cos(const Vec<Type, Size>& v) {
    auto c = v;
    for(auto& e : c.elements) {
        e = cos(e);
    }
    return c;
}

}
