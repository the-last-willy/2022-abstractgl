#pragma once

#include "agl/opengl/qualifier/program.hpp"

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
