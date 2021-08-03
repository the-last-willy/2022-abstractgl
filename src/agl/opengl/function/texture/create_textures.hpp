#pragma once

#include "agl/opengl/qualifier/texture_target.hpp"
#include "agl/opengl/qualifier/texture.hpp"

#include <span>

namespace agl {

inline
void create_textures(TextureTarget tt, GLsizei n, Texture* ts) {
    glCreateTextures(
        static_cast<GLenum>(tt),
        n,
        reinterpret_cast<GLuint*>(ts));
}

inline
void textures(TextureTarget tt, std::span<Texture> s) {
    create_textures(
        tt,
        static_cast<GLsizei>(size(s)),
        data(s));
}

Texture texture(TextureTarget tt) {
    auto t = Texture();
    create_textures(tt, 1, &t);
    return t;
}

}
