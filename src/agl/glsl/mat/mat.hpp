#pragma once

#include "agl/glsl/vec/vec.hpp"
#include "agl/tag/identity.hpp"

#include <array>
#include <type_traits>

namespace agl {

// template<typename T>
// concept SquareMatrix = requires {
//     T::column_count;
//     T::row_count;
// } && (T::column_count == T::row_count);

template<typename Type, std::size_t ColumnCount, std::size_t RowCount>
struct Mat {
    static constexpr auto column_count = ColumnCount;
    static constexpr auto row_count = RowCount;

    std::array<Vec<Type, RowCount>, ColumnCount> columns;

    // constexpr
    // Mat() noexcept = default;

    // template<SquareMatrix = Mat> constexpr
    // Mat(IdentityTag) {
    //     for(auto& e : columns) {
    //         e = 0.f;
    //     }
    //     for(std::size_t i = 0; i < ColumnCount; ++i) {
    //         columns[i][i] = identity;
    //     }
    // }

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
