#pragma once

#include <glad/glad.h>

#include <cstdlib>
#include <array>

namespace agl {

template<typename T, std::size_t N>
struct Vec {
    std::array<T, N> elements;

    constexpr
    auto operator[](std::size_t i) const {
        return elements[i];
    }

    constexpr
    auto& operator[](std::size_t i) {
        return elements[i];
    }

    constexpr
    auto xyz() const {
        return Vec<T, 3>{elements[0], elements[1], elements[2]};
    }
};

}
