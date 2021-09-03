#pragma once

#include "agl/opengl/name/all.hpp"

#include <span>

namespace agl {

inline
VertexArray create(VertexArrayTag) {
    GLuint name;
    glCreateVertexArrays(1, &name);
    return VertexArray(name);
}

}
