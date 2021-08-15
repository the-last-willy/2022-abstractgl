#pragma once

#include "agl/opengl/qualifier/texture_target.hpp"
#include "agl/opengl/name/all.hpp"

#include <span>

namespace agl {

inline
void delete_(std::span<Texture> s) {
    glDeleteTextures(
        static_cast<GLsizei>(size(s)),
        reinterpret_cast<GLuint*>(data(s)));
}

inline
void delete_(Texture t) {
    glDeleteTextures(
        1,
        reinterpret_cast<GLuint*>(&t));
}

}
