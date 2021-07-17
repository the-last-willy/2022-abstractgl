#pragma once

#include "vec.hpp"

namespace agl {

template<typename T, std::size_t N> constexpr
auto size(const Vec<T, N>& v) {
    return size(v.elements);
}

}
