#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void get(
    Shader s,
  	GLenum name,
  	GLint *parameters)
{
    glGetShaderiv(
        s,
        name,
        parameters);
}

inline
GLboolean compile_status(Shader s) {
    GLint i;
    get(s, GL_COMPILE_STATUS, &i);
    return static_cast<GLboolean>(i);
}

inline
GLint info_log_length(Shader s) {
    GLint i;
    get(s, GL_INFO_LOG_LENGTH, &i);
    return static_cast<GLboolean>(i);
}

}
