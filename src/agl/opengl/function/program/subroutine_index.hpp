#pragma once

#include "agl/opengl/enum/shader_type.hpp"
#include "agl/opengl/name/all.hpp"
#include "agl/opengl/qualifier/czstring.hpp"

namespace agl {

struct SubroutineIndex {
    GLuint value;

    operator GLuint() const noexcept {
        return value;
    }
};

static_assert(sizeof(SubroutineIndex) == sizeof(GLuint));

struct OptionalSubroutineIndex {
    GLuint value = GL_INVALID_INDEX;

    operator bool() const noexcept {
        return value != GL_INVALID_INDEX;
    }

    SubroutineIndex operator*() const {
        return SubroutineIndex{value};
    }
};

inline
OptionalSubroutineIndex subroutine_index( 
    Program p,
  	ShaderType st,
  	czstring c)
{
    return OptionalSubroutineIndex{
        glGetSubroutineIndex(
            p,
            st,
            c)};
}
    
}
