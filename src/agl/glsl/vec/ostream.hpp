#pragma once

#include "size.hpp"
#include "vec.hpp"

#include <iostream>

namespace agl {

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const Vec<T, N>& v) {
    os << "[";
    if(size(v) > 0) {
        os << v[0];
        for(std::size_t i = 1; i < size(v); ++i) {
            os << ", " << v[i];
        }
    }
    os << "]";
    return os;
}

}
