#pragma once

namespace agl::opengl {

/**
 * Texture unit.
 */
struct TexUnit {
    GLuint value;

    operator GLuint() const noexcept {
        return value;
    }
};

}
