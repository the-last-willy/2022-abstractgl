#pragma once

#include "agl/opengl/qualifier/color_attachment.hpp"
#include "agl/opengl/tag/all.hpp"

namespace agl {

class FramebufferDrawBuffer {
    GLenum value;

public:
    explicit
    FramebufferDrawBuffer(GLenum e) noexcept
        : value(e)
    {}

    FramebufferDrawBuffer(ColorAttachment ca) noexcept
        : value(ca)
    {}

    operator GLenum() const noexcept {
        return value;
    }
};

}
