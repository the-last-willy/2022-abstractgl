#pragma once

#include "interval.hpp"
#include "length.hpp"
#include "lower_bound.hpp"

namespace agl::common {

template<typename... I> constexpr
auto mapping(const Interval<I...>& src, const Interval<I...>& dst) {
    auto a = length(dst) / length(src);
    auto b = - lower_bound(src) * a + lower_bound(dst);
    return [a, b](auto x) {
        return a * x + b; };
}

}
