#pragma once

#include "agl/opengl/enum/shader_type.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
Shader create(ShaderType st) {
    return Shader(glCreateShader(st));
}

}
