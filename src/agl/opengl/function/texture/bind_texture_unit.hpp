#pragma once

#include "agl/opengl/qualifier/texture.hpp"

namespace agl {

inline
void bind_texture_unit(GLuint unit, Texture t) {
    glBindTextureUnit(unit, t);
}

inline
void bind_unit(GLuint unit, Texture t) {
    bind_texture_unit(unit, t);
}

}
