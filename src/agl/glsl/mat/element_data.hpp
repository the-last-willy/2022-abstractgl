#pragma once

#include "mat.hpp"

namespace agl {

template<typename T, std::size_t CC, std::size_t RC> constexpr
const T* element_data(const Mat<T, CC, RC>& m) {
    return reinterpret_cast<const T*>(data(m.columns));
}

template<typename T, std::size_t CC, std::size_t RC> constexpr
const T* data(const Mat<T, CC, RC>& m) {
    return element_data(m);
}

}
