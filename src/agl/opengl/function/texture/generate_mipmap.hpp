#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
void generate_mipmap(agl::Texture t) {
    glGenerateTextureMipmap(t);
}

}
