#pragma once

#include <concepts>

namespace agl::common {

template<std::integral I> constexpr
auto pow(I base, I exponent) {
    auto value = I(1);
    for(std::size_t i = 0; i < exponent; ++i) {
        value *= base;
    }
    return value;
}

}
