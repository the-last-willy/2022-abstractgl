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

    BufferMapping() = default;

    BufferMapping(const BufferMapping&) = delete;

    BufferMapping(BufferMapping&& bm) {
        buffer = bm.buffer;
        mapping = bm.mapping;
        bm.mapping = nullptr;
    }

    ~BufferMapping() noexcept {
        if(mapping) {
            glUnmapNamedBuffer(*buffer);
        }
    }

    BufferMapping& operator=(const BufferMapping&) = delete;

    BufferMapping& operator=(BufferMapping&& bm) {
        if(mapping) {
            glUnmapNamedBuffer(*buffer);
        }
        buffer = bm.buffer;
        mapping = bm.mapping;
        bm.mapping = GL_NONE;
        return *this;
    }
};

inline
auto mapping(Buffer& b, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    auto bm = BufferMapping();
    bm.buffer = &b;
    bm.mapping = static_cast<std::byte*>(
        glMapNamedBufferRange(
            b, offset, length, access));
    return bm;
}

inline
auto mapping(Buffer& b, GLbitfield access) {
    return mapping(b, 0, size(b), access);
}

}
