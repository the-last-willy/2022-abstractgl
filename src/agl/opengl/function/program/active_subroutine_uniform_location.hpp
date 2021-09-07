#pragma once

#include "agl/opengl/enum/shader_type.hpp"
#include "agl/opengl/name/all.hpp"
#include "agl/opengl/qualifier/czstring.hpp"

namespace agl {

inline
GLint active_subroutine_uniform_locations(Program p, ShaderType st) {
    GLint i;
    glGetProgramStageiv(
        p,
        st,
        GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS,
        &i);
    return i;
}

}

