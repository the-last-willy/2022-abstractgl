#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
void compile(Shader s) {
    glCompileShader(s);
}

}
