#pragma once

#include "agl/opengl/qualifier/attribute_index.hpp"
#include "agl/opengl/qualifier/binding_index.hpp"
#include "agl/opengl/names.hpp"

namespace agl {

inline
void vertex_array_attrib_binding(
    VertexArray va,
    AttributeIndex<GLuint> ai,
    BindingIndex<GLuint> bi)
{
    glVertexArrayAttribBinding(
        static_cast<GLuint>(va),
        static_cast<GLuint>(ai),
        static_cast<GLuint>(bi));
}

inline
void attribute_binding(
    VertexArray va,
    AttributeIndex<GLuint> ai,
    BindingIndex<GLuint> bi)
{
    vertex_array_attrib_binding(va, ai, bi);
}

}
