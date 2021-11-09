#pragma once

#include "agl/opengl/enum/program_parameter.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void get(
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

inline
GLint info_log_length(Program p) {
    GLint i;
    get(p, ProgramParameter(GL_INFO_LOG_LENGTH), &i);
    return i;
}

inline
GLboolean link_status(
    Program p)
{
    GLint i;
    get(p, ProgramParameter::link_status, &i);
    return static_cast<GLboolean>(i);
}

}
