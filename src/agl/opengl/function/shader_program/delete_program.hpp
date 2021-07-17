#pragma once

#include "agl/opengl/qualifier/program.hpp"

namespace agl {

inline
void detele_program(Program p) {
    glDeleteProgram(static_cast<GLuint>(p));
}

inline
auto delete_(Program p) {
    detele_program(p);
}

}
