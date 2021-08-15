#pragma once

#include "agl/opengl/enum/framebuffer_target.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void bind(FramebufferTarget ft, Framebuffer f) {
    glBindFramebuffer(
        static_cast<GLenum>(ft),
        f);
}

inline
void unbind(FramebufferTarget ft) {
    glBindFramebuffer(
        static_cast<GLenum>(ft),
        0);
}

}
