#pragma once

#include "agl/opengl/enum/shader_type.hpp"
#include "agl/opengl/name/all.hpp"
#include "agl/opengl/qualifier/czstring.hpp"

namespace agl {

struct SubroutineUniformLocation {
    GLuint value;

    operator GLuint() const noexcept {
        return value;
    }
};

struct OptionalSubroutineUniformLocation {
    GLint value = -1;

    operator bool() const noexcept {
        return value != GL_INVALID_INDEX;
    }

    SubroutineUniformLocation operator*() const {
        return SubroutineUniformLocation{static_cast<GLuint>(value)};
    }
};

inline
OptionalSubroutineUniformLocation subroutine_uniform_location( 
    Program p,
  	ShaderType st,
  	czstring c)
{
    return OptionalSubroutineUniformLocation{
        glGetSubroutineUniformLocation(
            p,
            st,
            c)};
}

}
