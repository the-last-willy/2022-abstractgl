#pragma once

#include "agl/opengl/qualifier/cstring.hpp"
#include "agl/opengl/qualifier/program.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"

namespace agl {

inline
UniformIndex<GLint> get_uniform_location(Program p, cstring name) {
    return UniformIndex<GLint>(glGetUniformLocation(
            static_cast<GLuint>(p),
            name));
}

inline
UniformIndex<GLint> uniform_location(Program p, cstring name) {
    return get_uniform_location(p, name);
}

}
