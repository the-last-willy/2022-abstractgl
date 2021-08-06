#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
void link_program(Program p) {
    glLinkProgram(static_cast<GLuint>(p));
}

inline
void link(Program p) {
    link_program(p);
}

}
