#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void use(Program p) {
    glUseProgram(p);
}

}
