#pragma once

namespace agl::common {

// DOESNT HANDLE OPEN/CLOSED
template<typename T>
struct Interval {
    // INVARIANT: lb < ub NOT ENFORCED
    T lower_bound;
    T upper_bound;
};

template<typename T>
auto interval(T t0, T t1) {
    return Interval<T>(t0, t1);
}

template<typename T>
auto interval(T t) {
    return interval(t, t);
}

}
