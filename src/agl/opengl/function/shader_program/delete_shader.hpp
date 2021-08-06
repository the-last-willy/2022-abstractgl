#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
void detele_shader(Shader s) {
    glDeleteShader(static_cast<GLuint>(s));
}

inline
void delete_(Shader s) {
    detele_shader(s);
}

}
