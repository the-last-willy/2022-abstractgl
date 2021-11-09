#pragma once

#include "get_program.hpp"

#include "agl/opengl/name/all.hpp"

#include <string> 

namespace agl {

inline
void info_log( 
    Program p,
  	GLsizei maxLength,
  	GLsizei *length,
  	GLchar *infoLog)
{
    glGetProgramInfoLog(
        p,
        maxLength,
        length,
        infoLog);
}

inline
std::string info_log(Program p) {
    auto str = std::string();
    auto ill = info_log_length(p);
    str.resize(static_cast<std::size_t>(ill));
    GLsizei l;
    info_log(p, static_cast<GLsizei>(ill), &l, data(str));
    str.resize(static_cast<std::size_t>(l));
    return str;
}

}
