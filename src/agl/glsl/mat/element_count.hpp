#pragma once

#include "mat.hpp"

namespace agl {

template<typename T, std::size_t CC, std::size_t RC> constexpr
std::size_t element_count(const Mat<T, CC, RC>&) {
    return CC * RC;
} 

}
