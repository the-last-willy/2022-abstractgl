#pragma once

#include "type.hpp"

namespace agl {

template<>
struct Type<GLuint> {
    static constexpr GLenum enum_ = GL_UNSIGNED_INT;
};

}
