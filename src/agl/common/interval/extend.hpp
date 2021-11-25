#pragma once

#include "interval.hpp"
#include "lower_bound.hpp"
#include "upper_bound.hpp"

namespace agl::common {

template<typename... I> constexpr
void extend(Interval<I...>& i, auto&& arg) {
    auto& lb = lower_bound(i);
    auto& ub = upper_bound(i);
    for(std::size_t j = 0; j < size(lb); ++j) {
        if(arg[j] < lb[j]) {
            lb[j] = arg[j];
        } else if(arg[j] > ub[j]) {
            ub[j] = arg[j];
        }
    }
}

}
