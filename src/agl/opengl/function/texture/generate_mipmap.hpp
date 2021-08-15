#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void generate_mipmap(agl::Texture t) {
    glGenerateTextureMipmap(t);
}

}
