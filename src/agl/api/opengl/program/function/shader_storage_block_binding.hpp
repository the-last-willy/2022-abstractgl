#pragma once

#include "raii/all.hpp"

namespace agl::opengl {

inline
void ShaderStorageBlockBinding(
    const Program& p,
    const GLchar* name,
    GLuint storageBlockBinding)
{
    glShaderStorageBlockBinding(p,
        glGetProgramResourceIndex(p,
            GL_SHADER_STORAGE_BLOCK,
            name),
        storageBlockBinding);
}

}
