#pragma once

namespace agl {

template<typename T, std::size_t N> constexpr
auto mix(const Vec<T, N>& lt, const Vec<T, N>& rt, const Vec<T, N>& i) {
    return (vec<T, N>(1) - i) * lt + i * rt;
}

template<typename T, typename I> constexpr
auto mix(const T& lt, const T& rt, const I i) {
    return (I(1) - i) * lt + i * rt;
}

}
