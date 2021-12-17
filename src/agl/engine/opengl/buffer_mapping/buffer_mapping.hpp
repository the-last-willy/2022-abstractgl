#pragma once

#include "buffer/buffer.hpp"

#include <cstddef>

namespace agl::engine::opengl {

// Invariants:
// - RAII.
// - (TODO) Tie 'buffer' and 'data' ptr lifetimes smh.
struct BufferMapping {
    Buffer* buffer;
    std::byte* mapping = nullptr;

    ~BufferMapping() noexcept {
        glUnmapBuffer(buffer->name);
    }
};

inline
auto buffer_mapping(Buffer& b, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    auto bm = BufferMapping();
    bm.buffer = &b;
    bm.mapping = static_cast<std::byte*>(
        glMapNamedBufferRange(
            b.name, offset, length, access));
    return bm;
}

inline
auto buffer_mapping(Buffer& b, GLbitfield access) {
    return buffer_mapping(b, 0, size(b), access);
}

}
