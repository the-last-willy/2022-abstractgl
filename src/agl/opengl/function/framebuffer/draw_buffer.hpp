#pragma once

#include "agl/opengl/enum/framebuffer_draw_buffer.hpp"
#include "agl/opengl/name/all.hpp"

#include <span>

namespace agl {

inline
void draw_buffer(Framebuffer f, FramebufferDrawBuffer fdb) {
    glNamedFramebufferDrawBuffer(
        f,
        fdb);
}

inline
void draw_buffers(Framebuffer f, std::span<FramebufferDrawBuffer> s) {
    glNamedFramebufferDrawBuffers(
        f,
        static_cast<GLsizei>(size(s)),
        reinterpret_cast<GLenum*>(data(s)));
}

}
