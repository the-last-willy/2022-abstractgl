#pragma once

#include "agl/opengl/enum/texture_parameter.hpp"
#include "agl/opengl/names.hpp"

namespace agl {

inline
void texture_parameter(Texture t, TextureParameter tp, GLfloat param) {
    glTextureParameterf(
        t,
        static_cast<GLenum>(tp),
        param);
}

inline
void texture_parameter(Texture t, TextureParameter tp, GLint param) {
    glTextureParameteri(
        t,
        static_cast<GLenum>(tp),
        param);
}

template<typename Parameter>
void parameter(Texture t, TextureParameter tp, Parameter p) {
    texture_parameter(t, tp, p);
}

}
