#pragma once

#include <glad/glad.h>

namespace agl {

enum class TextureAttachment : GLenum {
    color0 = GL_COLOR_ATTACHMENT0,
    depth = GL_DEPTH_ATTACHMENT,
    depth_stencil = GL_DEPTH_STENCIL_ATTACHMENT,
    stencil = GL_STENCIL_ATTACHMENT,
};

// 'i' must be less than 'GL_MAX_COLOR_ATTACHMENTS'.
inline
TextureAttachment color_attachment(GLenum i) {
    return static_cast<TextureAttachment>(
        static_cast<GLenum>(TextureAttachment::color0) + i);
}

}
