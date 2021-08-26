#pragma once

#include "agl/glsl/vec/vec.hpp"

namespace agl {

template<typename T>
struct Quaternion {
    using Pure = Vec<T, 3>;

    T real = T(1);
    Pure pure = Pure{T(0), T(0), T(0)};
    
    constexpr
    Quaternion() noexcept = default;

    constexpr
    Quaternion(T real, Pure p)
        : real(real)
        , pure(p)
    {}
};

}
