#pragma once

#include "agl/opengl/qualifier/Level.hpp"
#include "agl/opengl/qualifier/texture.hpp"
#include "agl/opengl/qualifier/parameter/height.hpp"
#include "agl/opengl/qualifier/parameter/width.hpp"

namespace agl {

inline
void storage(
    Texture t,
    GLsizei levels,
    GLenum internalformat,
    Width w,
    Height h)
{
    glTextureStorage2D(
        t,
        levels,
        internalformat,
        w,
        h);
}

inline
void storage(
    Texture t,
    GLenum internalformat,
    Width w,
    Height h)
{
    storage(
        t,
        1,
        internalformat,
        w,
        h);
}

}
