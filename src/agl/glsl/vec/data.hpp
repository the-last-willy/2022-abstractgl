#pragma once

#include "vec.hpp"

namespace agl {

template<typename T, std::size_t N> constexpr
auto data(const Vec<T, N>& v) {
    return data(v.elements);
}

template<typename T, std::size_t N> constexpr
auto data(Vec<T, N>& v) {
    return data(v.elements);
}

}
