#pragma once

#include "agl/opengl/enum/framebuffer_attachment.hpp"
#include "agl/opengl/qualifier/level.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void texture(
    Framebuffer f,
    FramebufferAttachment fa,
    Texture t,
    Level l,
    GLint layer)
{
    glNamedFramebufferTextureLayer(
        f,
        fa,
        t,
        l,
        layer);
}

inline
void texture(
    Framebuffer f,
    FramebufferAttachment fa,
    Texture t,
    Level l = Level(0))
{
    glNamedFramebufferTexture(
        f,
        fa,
        t,
        l);
}

}
