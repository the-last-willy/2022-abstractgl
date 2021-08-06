#pragma once

#include "agl/opengl/names.hpp"
#include "agl/opengl/names.hpp"

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
