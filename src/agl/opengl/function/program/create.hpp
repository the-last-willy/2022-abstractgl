#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
Program create(ProgramTag) {
    return Program(glCreateProgram());
}

}
