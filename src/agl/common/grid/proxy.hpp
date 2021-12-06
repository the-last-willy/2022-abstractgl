#pragma once

#include "at.hpp"
#include "grid.hpp"

#include <array>
#include <cmath>

namespace agl::common {

template<typename T, std::size_t N>
struct MutableGridProxy {
    Grid<T>* grid;
    std::array<std::size_t, std::max(N - 1, 0)> offsets;

    constexpr
    auto& operator()(std::size_t i) const {
        return at(*grid, i);
    }

    constexpr
    auto& operator()(std::size_t i) {
        return at(*grid, i);
    }

    template<std::size_t = N>
    auto& operator()(std::size_t i0, std::size_t i1) const {
        return at(*grid, i0 * offsets[0] + i1);
    }

    template<std::size_t = N>
    auto& operator()(std::size_t i0, std::size_t i1) {
        return at(*grid, i0 * offsets[0] + i1);
    }
};

// template<std::size_t N, typename T> constexpr
// auto proxy(Grid<T>& g) {
//     auto mgp = MutableGridProxy<T, N>();
//     mgp.grid = &g;
//     if constexpr(N == 2) {

//     } else {
//         static_assert(false);
//     }
//     return mgp;
// }

}
