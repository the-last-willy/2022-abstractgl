#pragma once

#include "agl/opengl/qualifier/enum/framebuffer_target.hpp"
#include "agl/opengl/qualifier/framebuffer.hpp"

namespace agl {

inline
void bind(FramebufferTarget ft, Framebuffer f) {
    glBindFramebuffer(
        static_cast<GLenum>(ft),
        f);
}

inline
void bind_default(FramebufferTarget ft) {
    glBindFramebuffer(
        static_cast<GLenum>(ft),
        0);
}

}
