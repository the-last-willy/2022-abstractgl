#pragma once

#include "vec.hpp"

#include "agl/opengl/type/type.hpp"

namespace agl {

template<typename T, std::size_t N> constexpr
auto size(Type<Vec<T, N>>) {
    return N;
}

template<typename T, std::size_t N> constexpr
auto size(const Vec<T, N>&) {
    return N;
}

}
