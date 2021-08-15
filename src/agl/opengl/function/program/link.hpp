#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void link(Program p) {
    glLinkProgram(static_cast<GLuint>(p));
}

}
