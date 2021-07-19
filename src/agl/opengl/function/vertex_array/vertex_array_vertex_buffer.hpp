#pragma once

#include "agl/opengl/qualifier/binding_index.hpp"
#include "agl/opengl/qualifier/buffer.hpp"
#include "agl/opengl/qualifier/offset.hpp"
#include "agl/opengl/qualifier/stride.hpp"
#include "agl/opengl/qualifier/vertex_array.hpp"

namespace agl {

inline
void vertex_array_vertex_buffer(
    VertexArray va,
    BindingIndex<GLuint> bi,
    Buffer b,
    Offset<GLintptr> o,
    Stride<GLsizei> s)
{
    glVertexArrayVertexBuffer(
        va,
        bi,
        b,
        o,
        s);
}

inline
void vertex_buffer(
    VertexArray va,
    BindingIndex<GLuint> bi,
    Buffer b,
    Offset<GLintptr> o,
    Stride<GLsizei> s)
{
    vertex_array_vertex_buffer(va, bi, b, o, s);
}

}
