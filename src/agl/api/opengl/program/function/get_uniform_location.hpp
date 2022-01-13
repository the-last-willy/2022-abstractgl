#pragma once

#include "raii/all.hpp"
#include "type/optional_uniform_location.hpp"

namespace agl::opengl {

inline
OptUniformLoc
GetUniformLocation(
    const Program& program,
    const GLchar* name)
{
    return glGetUniformLocation(
        program,
        name);
}

}
