#pragma once

#include "agl/opengl/enum/texture_parameter.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void parameter(Sampler s, TextureParameter tp, GLfloat param) {
    glSamplerParameterf(
        s,
        static_cast<GLenum>(tp),
        param);
}

inline
void parameter(Sampler s, TextureParameter tp, GLint param) {
    glSamplerParameteri(
        s,
        static_cast<GLenum>(tp),
        param);
}

inline
void mag_filter(Sampler s, GLint param) {
    parameter(s, TextureParameter::mag_filter, param);
}

inline
void min_filter(Sampler s, GLint param) {
    parameter(s, TextureParameter::min_filter, param);
}

}
