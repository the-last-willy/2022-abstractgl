#pragma once

#include "agl/opengl/qualifier/buffer.hpp"
#include "agl/opengl/qualifier/vertex_array.hpp"

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
