#pragma once

#include "agl/glsl/mat/mat.hpp"
#include "agl/glsl/vec/vec.hpp"
#include "agl/opengl/qualifier/attribute_index.hpp"
#include "agl/opengl/qualifier/normalized.hpp"
#include "agl/opengl/qualifier/offset.hpp"
#include "agl/opengl/qualifier/size.hpp"
#include "agl/opengl/type/type.hpp"
#include "agl/opengl/qualifier/vertex_array.hpp"

namespace agl {

inline
void vertex_array_attrib_format(
    VertexArray va,
    AttributeIndex<GLint> ai,
    Size<GLint> s,
    GLenum type,
    Normalized n,
    Offset<GLuint> o)
{
    glVertexArrayAttribFormat(
        va,
        static_cast<GLint>(ai),
        s,
        type,
        n,
        o);
}

inline
void attribute_format(
    VertexArray va,
    AttributeIndex<GLint> ai,
    Size<GLint> s,
    GLenum type,
    Normalized n = Normalized(GL_FALSE),
    Offset<GLuint> o = Offset<GLuint>(0))
{
    vertex_array_attrib_format(
        va, ai, s, type, n, o);
}

}
