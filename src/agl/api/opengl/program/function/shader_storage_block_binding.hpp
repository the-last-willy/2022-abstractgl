#pragma once

#include "raii/all.hpp"

#include <stdexcept>

namespace agl::opengl {

inline
void ShaderStorageBlockBinding(
    const Program& program,
    const GLchar* name,
    GLuint storageBlockBinding)
{
    GLuint storageBlockIndex = glGetProgramResourceIndex(
        program,
        GL_SHADER_STORAGE_BLOCK,
        name);
    if(storageBlockIndex == GL_INVALID_INDEX) {
        throw std::runtime_error(
            "Not the name of a resource.");
    }
    glShaderStorageBlockBinding(program,
        storageBlockIndex,
        storageBlockBinding);
}

}
