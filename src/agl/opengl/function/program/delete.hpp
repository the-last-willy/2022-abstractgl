#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
void delete_(Program p) {
    glDeleteProgram(p);
}

}
