#pragma once

#include "agl/opengl/qualifier/program.hpp"
#include "agl/opengl/qualifier/shader.hpp"

namespace agl {

inline
void attach_shader(Program p, Shader s) {
    glAttachShader(p, s);
}

inline
void attach(Program p, Shader s) {
    attach_shader(p, s);
}

}
