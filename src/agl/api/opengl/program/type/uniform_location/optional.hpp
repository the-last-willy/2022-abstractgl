#pragma once

namespace agl::opengl {

/**
 * Optional uniform location.
 */
class OptUniformLoc {
    GLint value = -1;

public:
    constexpr
    OptUniformLoc() noexcept
        : value(-1)
    {}

    constexpr
    OptUniformLoc(GLint value) noexcept
        : value(value)
    {}

    constexpr
    operator GLint() const noexcept {
        return value;
    }
};

}
