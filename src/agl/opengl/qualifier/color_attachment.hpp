#pragma once

namespace agl {

struct ColorAttachment {
    GLenum value;

    explicit
    ColorAttachment(GLenum i)
        : value(GL_COLOR_ATTACHMENT0 + i)
    {}

    operator GLenum() const noexcept {
        return value;
    }
};

}
