#pragma once

#include "agl/opengl/qualifier/attribute_index.hpp"
#include "agl/opengl/names.hpp"

namespace agl {

inline
void disable_vertex_array_attrib(
    VertexArray va,
    AttributeIndex<GLuint> ai)
{
    glDisableVertexArrayAttrib(
        static_cast<GLuint>(va),
        static_cast<GLuint>(ai));
}

inline
void disable(VertexArray va, AttributeIndex<GLuint> ai) {
    disable_vertex_array_attrib(va, ai);
}

}
