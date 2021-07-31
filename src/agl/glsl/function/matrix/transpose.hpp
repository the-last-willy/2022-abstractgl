#pragma once

#include "agl/glsl/mat/mat.hpp"

namespace agl {

template<typename Type, std::size_t CC, std::size_t RC> constexpr
auto transpose(const Mat<Type, CC, RC>& m) {
    auto t = Mat<Type, RC, CC>();
    for(std::size_t c = 0; c < CC; ++c)
    for(std::size_t r = 0; r < RC; ++r) {
        t[r][c] = m[c][r];
    }
    return t;
}

}
