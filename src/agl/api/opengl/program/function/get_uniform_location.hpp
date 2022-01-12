#pragma once

#include "raii/all.hpp"
#include "type/uniform_location/optional.hpp"

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
