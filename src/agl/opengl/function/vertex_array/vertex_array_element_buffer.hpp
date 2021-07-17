#pragma once

#include "agl/opengl/qualifier/buffer.hpp"
#include "agl/opengl/qualifier/vertex_array.hpp"

namespace agl {

inline
void vertex_array_element_buffer(VertexArray va, Buffer b) {
    glVertexArrayElementBuffer(
        static_cast<GLuint>(va),
        static_cast<GLuint>(b));
}

inline
void element_buffer(VertexArray va, Buffer b) {
    vertex_array_element_buffer(va, b);
}

}
