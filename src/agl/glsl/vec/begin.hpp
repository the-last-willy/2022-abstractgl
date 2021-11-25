#pragma once

#include "vec.hpp"

namespace agl {

template<typename T, std::size_t N> constexpr
auto begin(const Vec<T, N>& v) {
    return begin(v.elements);
}

template<typename T, std::size_t N> constexpr
auto begin(Vec<T, N>& v) {
    return begin(v.elements);
}

}
