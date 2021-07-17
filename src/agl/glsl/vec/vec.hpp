#pragma once

#include <glad/glad.h>

#include <cstdlib>
#include <array>

namespace agl {

template<typename T, std::size_t N>
struct Vec {
    std::array<T, N> elements;

    auto operator[](std::size_t i) const {
        return elements[i];
    }

    auto& operator[](std::size_t i) {
        return elements[i];
    }
};

constexpr
auto vec2(float e0, float e1) noexcept {
    return Vec<float, 2>{e0, e1};
}

constexpr
auto vec3(float e0, float e1, float e2) noexcept {
    return Vec<float, 3>{e0, e1, e2};
}

constexpr
auto vec3(Vec<float, 2> v01, float e2) noexcept {
    return vec3(v01[0], v01[1], e2);
}

constexpr
auto vec4(float e0, float e1, float e2, float e3) noexcept {
    return Vec<float, 4>{e0, e1, e2, e3};
}

constexpr
auto vec4(Vec<float, 3> v012, float e3) noexcept {
    return vec4(v012[0], v012[1], v012[2], e3);
}

}
