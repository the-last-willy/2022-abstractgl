#pragma once

#include "agl/opengl/name/all.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
agl::Buffer element_array_buffer_binding(VertexArray va) {
    int i;
    glGetVertexArrayiv(
        va,
  	    GL_ELEMENT_ARRAY_BUFFER_BINDING,
  	    &i);
    return agl::Buffer(static_cast<GLuint>(i));
}

}
