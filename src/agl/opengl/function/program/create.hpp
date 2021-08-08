#pragma once

#include "agl/opengl/names.hpp"

namespace agl {

inline
Program create(ProgramTag) {
    return Program(glCreateProgram());
}

}
