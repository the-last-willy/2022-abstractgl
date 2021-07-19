#pragma once

#include <glad/glad.h>

namespace agl {

template<typename Value>
struct Parameter {
    constexpr Parameter() = default;

    constexpr explicit Parameter(Value value) noexcept
        : value(value)
    {}

    constexpr operator auto() const noexcept {
        return value;
    }

    Type value;
};

}
