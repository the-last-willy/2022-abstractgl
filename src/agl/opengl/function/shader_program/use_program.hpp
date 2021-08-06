#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
void use_program(Program p) {
    glUseProgram(p);
}

inline
void use(Program p) {
    use_program(p);
}

}
