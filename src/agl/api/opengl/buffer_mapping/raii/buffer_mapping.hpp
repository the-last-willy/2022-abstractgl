#pragma once

#include "buffer/buffer.hpp"

#include <cstddef>

namespace agl::opengl {

/**
 * Interface:
 * - 'BufferMapping's are returned by the '*MapBuffer*' OpenGL functions; as 
 * such, they should have pointer semantics.
 * Invariant:
 * - RAII.
 */
struct BufferMapping {
    // Has to be first in case of reinterpret_cast (type aliasing or whatever) ?
    void* mapping = nullptr;
    const Buffer* buffer;

    BufferMapping(const Buffer& b, void* ptr)
        : mapping(&ptr)
        , buffer(&b)
    {}

    BufferMapping(const BufferMapping&) = delete;

    BufferMapping(BufferMapping&& bm) noexcept {
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

    BufferMapping& operator=(BufferMapping&& bm) noexcept {
        if(mapping) {
            glUnmapNamedBuffer(*buffer);
        }
        buffer = bm.buffer;
        mapping = bm.mapping;
        bm.mapping = GL_NONE;
        return *this;
    }

    operator void* () const noexcept {
        return mapping;
    }
};

}
