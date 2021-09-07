#pragma once

#include "subroutine_index.hpp"

#include "agl/opengl/enum/shader_type.hpp"
#include "agl/opengl/qualifier/czstring.hpp"

#include <span>

namespace agl {

inline
void uniform_subroutines(ShaderType st, std::span<SubroutineIndex> sp) {
    glUniformSubroutinesuiv(
        st,
        static_cast<GLsizei>(size(sp)),
        reinterpret_cast<GLuint*>(data(sp)));
}

}
