#pragma once

namespace agl::opengl {

class EnabledCap {
    GLenum value;

public:

    EnabledCap() = delete;

    constexpr
    EnabledCap(GLenum cap) noexcept
        : value(cap)
    {}

    EnabledCap(const EnabledCap&) = delete;

    EnabledCap(EnabledCap&&) = delete;

    constexpr
    operator GLenum() const noexcept {
        return value;
    }
};

}
