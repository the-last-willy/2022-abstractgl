#pragma once

#include "function/disable.hpp"

namespace agl::opengl {


class [[nodiscard]] ScopedCap {
    GLenum cap;
    bool empty;

public:
    constexpr
    ScopedCap() noexcept
        : empty(true)
    {}

    ScopedCap(GLenum cap) noexcept
        : cap(cap)
        , empty(false)
    {}

    ScopedCap(const ScopedCap&) = delete;

    ScopedCap(ScopedCap&& sc)
        : cap(sc.cap)
        , empty(false)
    {
        sc.empty = true;
    }

    ~ScopedCap() noexcept {
        if(not empty) {
            Disable(cap);
        }
    }

    ScopedCap& operator=(const ScopedCap&) = delete;
    ScopedCap& operator=(ScopedCap&&) = delete;

    constexpr
    operator GLenum() const noexcept {
        return cap;
    }
};

}
