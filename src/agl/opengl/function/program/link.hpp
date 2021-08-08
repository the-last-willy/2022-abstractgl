#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
void link(Program p) {
    glLinkProgram(static_cast<GLuint>(p));
}

}
