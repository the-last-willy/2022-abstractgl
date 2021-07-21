#pragma once

#include <glad/glad.h>

namespace agl {

enum class TextureParameter : GLenum {
    // GL_DEPTH_STENCIL_TEXTURE_MODE,
    base_level = GL_TEXTURE_BASE_LEVEL,
    compare_func = GL_TEXTURE_COMPARE_FUNC,
    compare_mode = GL_TEXTURE_COMPARE_MODE,
    lod_bias = GL_TEXTURE_LOD_BIAS,
    mag_filter = GL_TEXTURE_MAG_FILTER,
    max_level = GL_TEXTURE_MAX_LEVEL,
    max_lod = GL_TEXTURE_MAX_LOD,
    min_filter = GL_TEXTURE_MIN_FILTER,
    min_lod = GL_TEXTURE_MIN_LOD,
    swizzle_a = GL_TEXTURE_SWIZZLE_A,
    swizzle_b = GL_TEXTURE_SWIZZLE_B,
    swizzle_g = GL_TEXTURE_SWIZZLE_G,
    swizzle_r = GL_TEXTURE_SWIZZLE_R,
    wrap_r = GL_TEXTURE_WRAP_R,
    wrap_s = GL_TEXTURE_WRAP_S,
    wrap_t = GL_TEXTURE_WRAP_T,
};

}
