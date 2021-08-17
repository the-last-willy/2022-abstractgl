#pragma once

#include "agl/opengl/qualifier/color_attachment.hpp"
#include "agl/opengl/tag/all.hpp"

namespace agl {

class FramebufferAttachment {
    GLenum value;

public:
    explicit
    FramebufferAttachment(GLenum e) noexcept
        : value(e)
    {}

    FramebufferAttachment(ColorAttachment ca) noexcept
        : value(ca)
    {}

    FramebufferAttachment(DepthTag) noexcept
        : value(GL_DEPTH_ATTACHMENT)
    {}

    FramebufferAttachment(StencilTag) noexcept
        : value(GL_STENCIL_ATTACHMENT)
    {}

    operator GLenum() const noexcept {
        return value;
    }
};

}
