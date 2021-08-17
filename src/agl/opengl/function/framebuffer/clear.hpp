#pragma once

#include "agl/opengl/name/all.hpp"
#include "agl/opengl/tag/all.hpp"

#include <array>

namespace agl {

inline
void clear(
    Framebuffer f,
    ColorTag,
    std::array<GLfloat, 4> value)
{
    glClearNamedFramebufferfv(
        f,
        GL_COLOR,
        0,
        data(value));
}

inline
void clear(
    Framebuffer f,
    DepthTag,
    float value)
{
    glClearNamedFramebufferfv(
        f,
        GL_DEPTH,
        0,
        &value);
}

}
