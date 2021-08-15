#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
Program create(tag::Program) {
    return Program(glCreateProgram());
}

}
