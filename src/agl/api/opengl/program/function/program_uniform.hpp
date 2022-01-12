#pragma once

#include "raii/all.hpp"

#include <concepts>

namespace agl::opengl {

inline
void ProgramUniform3fv(
    const Program& p,
    GLint location,
    std::array<GLfloat, 3> value)
{
    glProgramUniform3fv(
        p,
        location,
        1,
        data(value));
}

inline
void ProgramUniform4fv(
    const Program& p,
    GLint location,
    std::array<GLfloat, 4> value)
{
    glProgramUniform4fv(
        p,
        location,
        1,
        data(value));
}

}
