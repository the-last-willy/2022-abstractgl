#pragma once

#include "agl/opengl/name/all.hpp"
#include "agl/opengl/tag/names.hpp"

namespace agl {

inline
void bind_vertex_array(VertexArray va) {
    glBindVertexArray(static_cast<GLuint>(va));
}

inline
void bind(VertexArray va) {
    bind_vertex_array(va);
}

inline
void unbind(agl::VertexArrayTag) {
    glBindVertexArray(GL_NONE);
}

}
