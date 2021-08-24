#pragma once

#include "get.hpp"

#include "agl/opengl/name/all.hpp"

#include <string> 

namespace agl {

inline
void info_log( 
    Shader s,
  	GLsizei maxLength,
  	GLsizei *length,
  	GLchar *infoLog)
{
    glGetShaderInfoLog(
        s,
        maxLength,
        length,
        infoLog);
}

inline
std::string info_log(Shader s) {
    auto str = std::string();
    auto ill = info_log_length(s);
    str.resize(static_cast<std::size_t>(ill));
    GLsizei l;
    info_log(s, static_cast<GLsizei>(ill), &l, data(str));
    str.resize(static_cast<std::size_t>(l));
    return str;
}

}
