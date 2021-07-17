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

}
