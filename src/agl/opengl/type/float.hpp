#pragma once

#include "type.hpp"

namespace agl {

template<>
struct Type<GLfloat> {
    static constexpr GLenum enum_ = GL_FLOAT;
};

}
