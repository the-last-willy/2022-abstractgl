#pragma once

#include "optional_attribute_location.hpp"

namespace agl::opengl {

class AttribLoc {
    GLuint value;

public:
    constexpr
    AttribLoc(GLuint value) noexcept
        : value(value)
    {}

    constexpr
    AttribLoc(OptAttribLoc l)
        : value(static_cast<GLint>(l))
    {}

    constexpr
    operator GLuint() const noexcept {
        return value;
    }
};

}
