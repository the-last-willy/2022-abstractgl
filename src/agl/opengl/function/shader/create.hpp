#pragma once

#include "agl/opengl/qualifier/shader_type.hpp"
#include "agl/opengl/names.hpp"

namespace agl {

inline
Shader create(ShaderType st) {
    return Shader(glCreateShader(static_cast<GLenum>(st)));
}

}
