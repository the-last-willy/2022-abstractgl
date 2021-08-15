#pragma once

#include "agl/opengl/qualifier/texture_unit.hpp"
#include "agl/opengl/names.hpp"

namespace agl {

inline
void bind(TextureUnit tu, Texture t) {
    glBindTextureUnit(
        tu,
        t);
}

inline
void unbind(TextureUnit tu) {
    glBindTextureUnit(
        tu,
        0);
}

}
