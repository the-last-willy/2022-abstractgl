#pragma once

#include "interval.hpp"
#include "lower_bound.hpp"
#include "upper_bound.hpp"

namespace agl::common {

template<typename... I> constexpr
auto projection(const Interval<I...>& i, std::size_t d) {
    return interval(lower_bound(i)[d], upper_bound(i)[d]);
}

}
