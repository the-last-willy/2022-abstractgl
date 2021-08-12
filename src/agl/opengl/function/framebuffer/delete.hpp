#pragma once

#include "agl/opengl/names.hpp"

#include <span>

namespace agl {

inline
void delete_(Framebuffer f) {
    glDeleteFramebuffers(1, &f.id);
}

inline
void delete_(std::span<Framebuffer> s) {
    glDeleteFramebuffers(
        static_cast<GLsizei>(size(s)),
        reinterpret_cast<GLuint*>(data(s)));
}

}
