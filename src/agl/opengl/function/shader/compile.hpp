#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void compile(Shader s) {
    glCompileShader(s);
}

}
