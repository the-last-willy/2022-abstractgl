#pragma once

#include <agl/opengl/all.hpp>

namespace eng {

struct BufferView {
    std::size_t buffer;

    agl::Size<GLint> byte_length = agl::Size<GLint>(0);
    agl::Offset<GLintptr> byte_offset = agl::Offset<GLintptr>(0);
    agl::Stride<GLsizei> byte_stride = agl::Stride<GLsizei>(0);

    // target attribute ?
};

}
