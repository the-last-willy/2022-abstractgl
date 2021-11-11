#pragma once

#include "interval.hpp"
#include "lower_bound.hpp"
#include "upper_bound.hpp"

#include <cmath>

namespace agl::common {

template<auto... I> constexpr
Interval<I...> union_bounds(const Interval<I...>& i0, const Interval<I...>& i1) {
    auto bounds = Interval<I...>();
    for(std::size_t j = 0; j < size(lower_bound(bounds)); ++j) {
        lower_bound(bounds) = min(lower_bound(i0), lower_bound(i1));
        upper_bound(bounds) = max(upper_bound(i0), upper_bound(i1));
    }
    return bounds;
}

}
