#pragma once

#include "type/all.hpp"

namespace agl::opengl {

// - RAII.
struct Texture {
    GLuint name = 0;

    template<typename = void>
    Texture() {
        static_assert(
            false,
            "An OpenGL texture cannot be default constructed; "
            "a texture target has to be specified.");
    }

    Texture(GLenum target) {
        glCreateTextures(target, 1, &name);
    }

    Texture(const Texture&) = delete;
    
    Texture(Texture&& va) {
        name = va.name;
        va.name = GL_NONE;
    }

    ~Texture() noexcept {
        glDeleteTextures(1, &name);
    }

    Texture& operator=(const Texture&) = delete;

    Texture& operator=(Texture&& va) {
        glDeleteTextures(1, &name);
        name = va.name;
        va.name = GL_NONE;
        return *this;
    }

    operator GLuint() const noexcept {
        return name;
    }
};

}
