#pragma once

#include "agl/opengl/names.hpp"

#include <span>

namespace agl {


inline
Framebuffer create(FramebufferTag) {
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
