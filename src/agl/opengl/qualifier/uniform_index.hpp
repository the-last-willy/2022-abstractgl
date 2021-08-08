#pragma once

#include "agl/common/optional.hpp"

namespace agl {

struct UniformIndex {
    GLuint value;

    constexpr explicit
    UniformIndex(GLuint i) noexcept
        : value(i)
    {}

    constexpr
    operator GLuint() const noexcept {
        return value;
    }
};

template<>
class Optional<UniformIndex> {
    GLint opt_value;

public:
    constexpr
    Optional(GLint opt_value) noexcept
        : opt_value(opt_value)
    {}

    constexpr
    UniformIndex operator*() const {
        return UniformIndex(static_cast<GLuint>(opt_value));
    }

    constexpr
    operator bool() const noexcept {
        return opt_value >= 0;
    }
};

}
