#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void delete_(Shader s) {
    glDeleteShader(s);
}

}
