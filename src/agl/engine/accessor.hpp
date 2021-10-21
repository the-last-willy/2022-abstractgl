#pragma once

#include "buffer.hpp"
#include "buffer_view.hpp"

#include <agl/opengl/all.hpp>

#include <memory>
#include <optional>
#include <vector>

namespace eng {

struct Accessor {
    Accessor() = default;

    Accessor(const Accessor&&) = delete;

    Accessor(Accessor&&) = default;

    std::size_t count = 0;

    agl::Offset<GLuint> byte_offset = agl::Offset<GLuint>(0);
    agl::Size<GLint> component_count = agl::Size<GLint>(0);

    // PROBABLY USELESS. REMOVE IT.
    int component_size = 0; // In bytes.

    GLenum component_type = GL_NONE;
    agl::Normalized normalized;

    std::vector<float> min = {};
    std::vector<float> max = {};

    // Buffer view.

    std::size_t buffer_view;

    // REMOVE THAT FROM HERE.
    agl::Stride<GLsizei> buffer_view_byte_stride = agl::Stride<GLsizei>(0);
    agl::Offset<GLintptr> buffer_view_byte_offset = agl::Offset<GLintptr>(0);

    // Buffer.
    

    // REMOVE THAT FROM HERE.
    std::shared_ptr<eng::Buffer> buffer = {};
};

template<typename T>
const T& at(const Accessor& a, std::size_t i) {
    auto& data = a.buffer->data;
    auto offset = static_cast<std::size_t>(a.buffer_view_byte_offset)
    + static_cast<std::size_t>(a.byte_offset)
    + i * static_cast<std::size_t>(a.buffer_view_byte_stride);
    return reinterpret_cast<const T&>(data[offset]);
}

template<typename T>
std::optional<T> min(const Accessor& a) {
    if(empty(a.min)) {
        return std::nullopt;
    } else {
        return *reinterpret_cast<const T*>(std::data(a.min));
    }
}

template<typename T>
std::optional<T> max(const Accessor& a) {
    if(empty(a.max)) {
        return std::nullopt;
    } else {
        return *reinterpret_cast<const T*>(std::data(a.max));
    }
}

}
