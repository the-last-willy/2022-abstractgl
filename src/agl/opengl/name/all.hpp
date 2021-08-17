#pragma once

#include "agl/opengl/tag/all.hpp"

#include "agl/common/scoped.hpp"

namespace agl {

template<typename Type>
concept NameTraits = true;

template<NameTraits NT>
struct Name {
    GLuint id = GL_NONE;

    constexpr
    Name() noexcept = default;

    constexpr
    Name(None) noexcept {}

    constexpr explicit
    Name(GLuint id) noexcept
        : id(id)
    {}

    constexpr
    operator bool() const noexcept {
        return id;
    }

    constexpr
    operator GLuint() const noexcept {
        return id;
    }
};

////////////////////////////////////////////////////////////////////////////////
// Buffer.

struct BufferTraits {
    static void delete_(GLuint id) {
        glDeleteBuffers(1, &id);
    }
};

using Buffer = Name<BufferTraits>;

////////////////////////////////////////////////////////////////////////////////
// Framebuffer.

struct FramebufferTraits {
    static void delete_(GLuint id) {
        glDeleteFramebuffers(1, &id);
    }
};

using Framebuffer = Name<FramebufferTraits>;

constexpr auto default_framebuffer = Framebuffer(0);

////////////////////////////////////////////////////////////////////////////////
// Program.

struct ProgramTraits {
    static void delete_(GLuint id) {
        glDeleteProgram(id);
    }
};

using Program = Name<ProgramTraits>;

////////////////////////////////////////////////////////////////////////////////
// Sampler.

struct SamplerTraits {
    static void delete_(GLuint id) {
        glDeleteSamplers(1, &id);
    }
};

using Sampler = Name<SamplerTraits>;

////////////////////////////////////////////////////////////////////////////////
// Shader.

struct ShaderTraits {
    static void delete_(GLuint id) {
        glDeleteShader(id);
    }
};

using Shader = Name<ShaderTraits>;

////////////////////////////////////////////////////////////////////////////////
// Texture.

struct TextureTraits {
    static void delete_(GLuint id) {
        glDeleteTextures(1, &id);
    }
};

using Texture = Name<TextureTraits>;

////////////////////////////////////////////////////////////////////////////////
// VertexArray.

struct VertexArrayTraits {
    static void delete_(GLuint id) {
        glDeleteVertexArrays(1, &id);
    }
};

using VertexArray = Name<VertexArrayTraits>;

}
