#pragma once

#include "vec.hpp"

namespace agl {

template<typename T, std::size_t N> constexpr
auto end(const Vec<T, N>& v) {
    return end(v.elements);
}

template<typename T, std::size_t N> constexpr
auto end(Vec<T, N>& v) {
    return end(v.elements);
}

}
