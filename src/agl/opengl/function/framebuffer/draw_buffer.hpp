#pragma once

#include "agl/opengl/enum/framebuffer_buffer.hpp"
#include "agl/opengl/name/all.hpp"

#include <span>

namespace agl {

inline
void draw_buffer(Framebuffer f, FramebufferBuffer fb) {
    glNamedFramebufferDrawBuffer(
        f,
        static_cast<GLenum>(fb));
}

inline
void draw_buffers(Framebuffer f, std::span<FramebufferBuffer> s) {
    glNamedFramebufferDrawBuffers(
        f,
        static_cast<GLsizei>(size(s)),
        reinterpret_cast<GLenum*>(data(s)));
}

}
