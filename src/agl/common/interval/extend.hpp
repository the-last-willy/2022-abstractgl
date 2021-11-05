#pragma once

#include "interval.hpp"
#include "lower_bound.hpp"
#include "upper_bound.hpp"

namespace agl::common {

template<auto... I> constexpr
void extend(Interval<I...>& i, auto&& arg) {
    auto& lb = lower_bound(i);
    auto& ub = upper_bound(i);
    for(std::size_t j = 0; j < size(lb); ++j) {
        if(arg < lb[j]) {
            lb[j] = arg;
        } else if(arg > ub[j]) {
            ub[j] = arg;
        }
    }
}

}
