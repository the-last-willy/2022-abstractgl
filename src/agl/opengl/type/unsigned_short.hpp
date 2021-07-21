#pragma once

#include "type.hpp"

namespace agl {

template<>
struct Type<GLushort> {
    static constexpr GLenum enum_ = GL_UNSIGNED_SHORT;
};

}
