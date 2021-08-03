#pragma once

#include <glad/glad.h>

namespace agl {

enum class FramebufferBuffer : GLenum {
    // Default framebuffer.
    // ...
    // Framebuffer object.
    color0 = GL_COLOR_ATTACHMENT0,
};

}
