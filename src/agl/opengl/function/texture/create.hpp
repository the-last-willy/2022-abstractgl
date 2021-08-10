#pragma once

#include "agl/opengl/qualifier/texture_target.hpp"
#include "agl/opengl/names.hpp"

#include <span>

namespace agl {

inline
void create(TextureTarget tt, std::span<Texture> s) {
    glCreateTextures(
        static_cast<GLenum>(tt),
        static_cast<GLsizei>(size(s)),
        reinterpret_cast<GLuint*>(data(s)));
}

Texture create(TextureTarget tt) {
    auto t = GLuint();
    glCreateTextures(
        static_cast<GLenum>(tt),
        1,
        &t);
    return Texture(t);
}

}
