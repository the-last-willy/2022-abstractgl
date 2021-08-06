#pragma once

#include "agl/opengl/names.hpp"

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
