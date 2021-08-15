#pragma once

#include "agl/opengl/name/all.hpp"

#include <span>

namespace agl {


inline
Framebuffer create(tag::Framebuffer) {
    auto f = Framebuffer();
    glCreateFramebuffers(1, &f.id);
    return f;
}

inline
void create(std::span<Framebuffer> s) {
    glCreateFramebuffers(
        static_cast<GLsizei>(size(s)),
        reinterpret_cast<GLuint*>(data(s)));
}

}
