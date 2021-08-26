#pragma once

#include "agl/glsl/vec/vec.hpp"

namespace agl {

template<typename T>
struct Quaternion {
    using Pure = Vec<T, 3>;

    T real = {};
    Pure pure = {};
    
    constexpr
    Quaternion() noexcept = default;

    constexpr
    Quaternion(T real, Pure p)
        : real(real)
        , pure(p)
    {}
};

}
