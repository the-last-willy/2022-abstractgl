#pragma once

#include "agl/opengl/qualifier/texture_target.hpp"
#include "agl/opengl/qualifier/texture.hpp"

#include <span>

namespace agl {

inline
void delete_textures(GLsizei n, Texture* ts) {
    glDeleteTextures(
        n,
        reinterpret_cast<GLuint*>(ts));
}

inline
void delete_(std::span<Texture> s) {
    delete_textures(
        static_cast<GLsizei>(size(s)),
        data(s));
}

inline
void delete_(Texture t) {
    delete_textures(1, &t);
}

}
