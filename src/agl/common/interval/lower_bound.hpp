#pragma once

#include "interval.hpp"

namespace agl::common {

template<typename... I> constexpr
auto lower_bound(const Interval<I...>& i) {
    return i.lower_bound;
}

template<typename... I> constexpr
auto& lower_bound(Interval<I...>& i) {
    return i.lower_bound;
}

}
