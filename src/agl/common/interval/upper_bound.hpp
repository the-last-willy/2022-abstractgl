#pragma once

#include "interval.hpp"

namespace agl::common {

template<auto... I> constexpr
auto upper_bound(const Interval<I...>& i) {
    return i.upper_bound;
}

template<auto... I> constexpr
auto& upper_bound(Interval<I...>& i) {
    return i.upper_bound;
}

}
