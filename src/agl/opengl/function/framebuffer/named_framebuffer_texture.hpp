#pragma once

#include "agl/opengl/qualifier/framebuffer.hpp"
#include "agl/opengl/qualifier/level.hpp"
#include "agl/opengl/qualifier/texture_attachment.hpp"
#include "agl/opengl/qualifier/texture.hpp"

namespace agl {

inline
void named_framebuffer_texture(
    Framebuffer f,
    TextureAttachment ta,
    Texture t,
    Level l)
{
    glNamedFramebufferTexture(
        f,
        static_cast<GLenum>(ta),
        t,
        l);
}

inline
void texture(
    Framebuffer f,
    TextureAttachment ta,
    Texture t,
    Level l = Level(0))
{
    named_framebuffer_texture(f, ta, t, l);
}

}
