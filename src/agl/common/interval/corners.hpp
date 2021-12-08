#pragma once

#include "interval.hpp"
#include "lower_bound.hpp"
#include "pow.hpp"
#include "upper_bound.hpp"

#include <agl/glsl/vec/all.hpp>

#include <array>

namespace agl::common {

template<typename T, std::size_t N>
auto corners(const Interval<agl::Vec<T, N>>& i) {
    auto lb = lower_bound(i);
    auto ub = upper_bound(i);
    auto corners = std::array<agl::Vec<T, N>, pow(std::size_t(2), N)>();
    for(std::size_t j = 0; j < size(corners); ++j) {
        auto& corner = corners[j];
        for(std::size_t k = 0; k < N; ++k) {
            corner[k] = (j & (std::size_t(1) << (N - k - 1))) ? ub[k] : lb[k];
        }
    }
    return corners;
}

}
