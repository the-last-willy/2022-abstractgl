#pragma once

#include "agl/opengl/qualifier/enum/program_parameter.hpp"
#include "agl/opengl/qualifier/program.hpp"

namespace agl {

inline
void get_program(
    Program p,
    ProgramParameter pp,
    GLint* params)
{
    glGetProgramiv(
        p,
        static_cast<GLenum>(pp),
        params);
}

inline
void get(
    Program p,
    ProgramParameter pp,
    GLint* params)
{
    get_program(p, pp, params);
}

inline
GLint active_attributes(
    Program p)
{
    GLint i;
    get(p, ProgramParameter::active_attributes, &i);
    return i;
}

inline
GLint active_attribute_max_length(
    Program p)
{
    GLint i;
    get(p, ProgramParameter::active_attribute_max_length, &i);
    return i;
}

inline
GLint active_uniforms(
    Program p)
{
    GLint i;
    get(p, ProgramParameter::active_uniforms, &i);
    return i;
}

inline
GLint active_uniform_max_length(
    Program p)
{
    GLint i;
    get(p, ProgramParameter::active_uniform_max_length, &i);
    return i;
}

}
