#pragma once

#include "agl/opengl/enum/texture_parameter.hpp"
#include "agl/opengl/names.hpp"

namespace agl {

inline
void parameter(Texture t, TextureParameter tp, GLfloat param) {
    glTextureParameterf(
        t,
        static_cast<GLenum>(tp),
        param);
}

inline
void parameter(Texture t, TextureParameter tp, GLint param) {
    glTextureParameteri(
        t,
        static_cast<GLenum>(tp),
        param);
}

inline
void mag_filter(Texture t, GLint param) {
    parameter(t, TextureParameter::mag_filter, param);
}

inline
void min_filter(Texture t, GLint param) {
    parameter(t, TextureParameter::min_filter, param);
}

}
