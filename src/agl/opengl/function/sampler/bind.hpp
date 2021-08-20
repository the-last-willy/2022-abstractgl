#pragma once

#include "agl/opengl/qualifier/texture_unit.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void bind(TextureUnit tu, Sampler s) {
    glBindSampler(
        tu,
        s);
}

inline
void unbind(TextureUnit tu, SamplerTag) {
    glBindSampler(
        tu,
        0);
}

}
