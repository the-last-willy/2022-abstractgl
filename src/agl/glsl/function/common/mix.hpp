#pragma once

namespace agl {

template<typename T, typename I> constexpr
auto mix(const T& lt, const T& rt, const I i) {
    return (I(1) - i) * lt + i * rt;
}

}
