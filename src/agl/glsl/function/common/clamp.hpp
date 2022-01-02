#pragma once

namespace agl {

template<typename T> constexpr
T clamp(T x, T min, T max) {
    if(x < min) {
        return min;
    } else if(x > max) {
        return max;
    } else {
        return x;
    }
}

}
