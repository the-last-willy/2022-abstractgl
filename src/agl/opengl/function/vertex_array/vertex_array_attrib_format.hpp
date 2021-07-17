#pragma once

#include "agl/opengl/qualifier/attribute_index.hpp"
#include "agl/opengl/qualifier/offset.hpp"
#include "agl/opengl/qualifier/size.hpp"
#include "agl/opengl/qualifier/vertex_array.hpp"

namespace agl {

inline
void vertex_array_attrib_format(
    VertexArray va,
    AttributeIndex<GLuint> ai,
    Size<GLint> size,
    GLenum type,
    GLboolean normalized,
    Offset<GLuint> o)
{
    glVertexArrayAttribFormat(
        static_cast<GLuint>(va),
        static_cast<GLuint>(ai),
        static_cast<GLint>(size),
        type,
        normalized,
        static_cast<GLuint>(o));
}

inline
void attribute_format(
    VertexArray va,
    AttributeIndex<GLuint> ai,
    Size<GLint> size,
    GLenum type,
    GLboolean normalized,
    Offset<GLuint> o)
{
    vertex_array_attrib_format(
        va, ai, size, type, normalized, o);
}

}
