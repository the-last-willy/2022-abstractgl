#pragma once

#include <glad/glad.h>

namespace agl {

enum class TextureTarget : GLenum {
    buffer = GL_TEXTURE_BUFFER,
    cube_map = GL_TEXTURE_CUBE_MAP,
    cube_map_array = GL_TEXTURE_CUBE_MAP_ARRAY,
    rectangle = GL_TEXTURE_RECTANGLE,
    _1d = GL_TEXTURE_1D,
    _1d_array = GL_TEXTURE_1D_ARRAY,
    _2d = GL_TEXTURE_2D,
    _2d_array = GL_TEXTURE_2D_ARRAY,
    _2d_multisample = GL_TEXTURE_2D_MULTISAMPLE,
    _2d_multisample_array = GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
    _3d = GL_TEXTURE_3D,
};

}
