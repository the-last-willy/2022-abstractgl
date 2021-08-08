#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
void use(Program p) {
    glUseProgram(p);
}

}
