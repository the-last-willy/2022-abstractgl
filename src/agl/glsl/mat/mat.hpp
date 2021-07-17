#pragma once

#include "agl/glsl/vec/vec.hpp"

#include <array>

namespace agl {

template<typename Type, std::size_t ColumnCount, std::size_t RowCount>
struct Mat {
    std::array<Vec<Type, RowCount>, ColumnCount> columns;

    constexpr
    auto operator[](std::size_t i) const {
        return columns[i];
    }

    constexpr
    auto& operator[](std::size_t i) {
        return columns[i];
    }
};

constexpr
auto mat2(
    float e00, float e01,
    float e10, float e11)
{
    return Mat<float, 2, 2>{
        e00, e01,
        e10, e11};
}

constexpr
auto mat3(
    float e00, float e01, float e02,
    float e10, float e11, float e12,
    float e20, float e21, float e22)
{
    return Mat<float, 3, 3>{
        e00, e01, e02,
        e10, e11, e12,
        e20, e21, e22};
}

constexpr
auto mat4(
    float e00, float e01, float e02, float e03,
    float e10, float e11, float e12, float e13,
    float e20, float e21, float e22, float e23,
    float e30, float e31, float e32, float e33)
{
    return Mat<float, 4, 4>{
        e00, e01, e02, e03,
        e10, e11, e12, e13,
        e20, e21, e22, e23,
        e30, e31, e32, e33};
}

}
