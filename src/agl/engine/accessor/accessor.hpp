#pragma once

#include "agl/engine/accessor.hpp"

#include <memory>
#include <span>
#include <stdexcept>

namespace agl::engine {

template<typename S>
auto accessor(const std::span<S>& s) {
    auto buffer = eng::Buffer();
    { // Fill buffer.
        buffer.opengl = create(agl::buffer_tag);
        agl::storage(buffer.opengl, s);
    }
    auto accessor = eng::Accessor();
    { // Fill buffer view.
        accessor.buffer = std::make_shared<eng::Buffer>(std::move(buffer));
        accessor.buffer_view_byte_stride = agl::Stride<GLsizei>(sizeof(S));
    }
    { // Fill accessor.
        accessor.component_count = agl::Size<GLint>(static_cast<GLint>(size(s)));
        accessor.normalized = agl::Normalized(false);
        // HARDCODED, DO SOMETHING BETTER.
        if(typeid(S) == typeid(agl::Vec<float, 2>)) {
            accessor.component_count = agl::Size<GLint>(2);
            accessor.component_type = GL_FLOAT;
        } else if(typeid(S) == typeid(agl::Vec<float, 3>)) {
            accessor.component_count = agl::Size<GLint>(3);
            accessor.component_type = GL_FLOAT;
        } else if(typeid(S) == typeid(float)) {
            accessor.component_count = agl::Size<GLint>(1);
            accessor.component_type = GL_FLOAT;
        } else if(typeid(S) == typeid(unsigned)) {
            accessor.component_count = agl::Size<GLint>(1);
            accessor.component_type = GL_UNSIGNED_INT;
        } else {
            throw std::logic_error(
                "agl::engine::accessor: Unhandled type.");
        }
    }
    return accessor;
}

}
