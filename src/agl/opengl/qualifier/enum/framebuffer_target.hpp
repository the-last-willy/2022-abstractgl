#pragma once

#include <glad/glad.h>

namespace agl {

enum class FramebufferTarget : GLenum {
    draw = GL_DRAW_FRAMEBUFFER,
    framebuffer = GL_FRAMEBUFFER,
    read = GL_READ_FRAMEBUFFER,
};

}
