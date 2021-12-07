#pragma once

#include "interval.hpp"
#include "lower_bound.hpp"
#include "upper_bound.hpp"

namespace agl::common {

template<typename... I, typename T> constexpr
auto clamp(const Interval<I...>& i, const T& arg) {
    auto c = T();
    auto lb = lower_bound(i);
    auto ub = upper_bound(i);
    for(std::size_t j = 0; j < size(lb); ++j) {
        if(arg[j] < lb[j]) {
            c[j] = lb[j];
        } else if(arg[j] > ub[j]) {
            c[j] = ub[j];
        } else {
            c[j] = arg[j];
        }
    }
    return c;
}

}
