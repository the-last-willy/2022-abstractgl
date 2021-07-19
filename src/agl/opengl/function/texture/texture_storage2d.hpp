#pragma once

#include "agl/opengl/qualifier/Level.hpp"
#include "agl/opengl/qualifier/texture.hpp"
#include "agl/opengl/qualifier/parameter/height.hpp"
#include "agl/opengl/qualifier/parameter/width.hpp"

namespace agl {

inline
void texture_storage2d(
    Texture t,
    GLsizei levels,
    GLenum internalformat,
    Width w,
    Height h)
{
    glTexStorage2D(
        t,
        levels,
        internalformat,
        w,
        h);
}

inline
void storage(
    Texture t,
    GLsizei levels,
    GLenum internalformat,
    Width w,
    Height h)
{
    texture_storage2d(t, levels, internalformat, w, h);
}

}
