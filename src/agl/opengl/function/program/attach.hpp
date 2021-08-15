#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void attach(Program p, Shader s) {
    glAttachShader(p, s);
}

}
