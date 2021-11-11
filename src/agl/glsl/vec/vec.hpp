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
    auto xy() const {
        return Vec<T, 2>{elements[0], elements[1]};
    }

    constexpr
    auto xyz() const {
        return Vec<T, 3>{elements[0], elements[1], elements[2]};
    }
};

template<typename T, std::size_t N> constexpr
auto vec(T t) {
    auto v = Vec<T, N>();
    for(auto& vi : v.elements) {
        vi = t;
    }
    return v;
}

}
