#pragma once

#include "agl/opengl/qualifier/program.hpp"

namespace agl {

inline
Program create_program() {
    return Program(glCreateProgram());
}

inline
Program program() {
    return create_program();
}

}
