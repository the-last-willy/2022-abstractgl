#pragma once

#include "agl/opengl/names.hpp"

#include <string_view> 

namespace agl {

inline
void source(
    Shader s,
    GLsizei count,
    const GLchar* const* string,
    const GLint* length)
{
    glShaderSource(
        static_cast<GLuint>(s),
        count,
        string,
        length);
}

inline
void source(Shader s, std::string_view src) {
    // Credits to Sp0nji for using std::string_view.
    auto d = data(src);
    auto si = static_cast<GLint>(size(src));
    source(s, 1, &d, &si);
}

}
