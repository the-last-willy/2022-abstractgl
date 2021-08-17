#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void bind(Framebuffer f) {
    glBindFramebuffer(
        GL_FRAMEBUFFER,
        f);
}

}
