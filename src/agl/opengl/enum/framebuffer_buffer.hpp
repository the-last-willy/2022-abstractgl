#pragma once

#include <glad/glad.h>

namespace agl {

enum class FramebufferBuffer : GLenum {
    // Default framebuffer.
    // ...
    // Framebuffer object.
    color0 = GL_COLOR_ATTACHMENT0,
    color1 = GL_COLOR_ATTACHMENT1,
    color2 = GL_COLOR_ATTACHMENT2,
    color3 = GL_COLOR_ATTACHMENT3,
    color4 = GL_COLOR_ATTACHMENT4,
};

}
