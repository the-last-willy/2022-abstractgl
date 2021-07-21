#pragma once

#include "type.hpp"

namespace agl {

template<>
struct Type<GLubyte> {
    static constexpr GLenum enum_ = GL_UNSIGNED_BYTE;
};

}
