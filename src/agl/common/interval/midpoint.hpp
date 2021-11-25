#pragma once

#include "interval.hpp"
#include "lower_bound.hpp"
#include "upper_bound.hpp"

namespace agl::common {

template<typename... I> constexpr
auto midpoint(const Interval<I...>& i) {
    return (upper_bound(i) + lower_bound(i)) / 2;
}

}
