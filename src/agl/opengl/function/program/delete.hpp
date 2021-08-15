#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void delete_(Program p) {
    glDeleteProgram(p);
}

}
