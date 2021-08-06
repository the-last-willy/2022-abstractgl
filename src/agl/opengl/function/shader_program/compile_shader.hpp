#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
void compile_shader(Shader s) {
    glCompileShader(static_cast<GLuint>(s));
}

inline
void compile(Shader s) {
    compile_shader(s);
}

}
