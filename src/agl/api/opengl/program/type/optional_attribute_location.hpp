#pragma once

namespace agl::opengl {

/**
 * Optional attribute location.
 */
class OptAttribLoc {
    GLint value = -1;

public:
    constexpr
    OptAttribLoc() noexcept
        : value(-1)
    {}

    constexpr
    OptAttribLoc(GLint value) noexcept
        : value(value)
    {}

    constexpr
    operator GLint() const noexcept {
        return value;
    }
};

}
