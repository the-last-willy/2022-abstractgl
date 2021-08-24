#pragma once

#include "agl/common/optional.hpp"

namespace agl {

class FragDataLocation {
    GLuint index;

public:
    constexpr explicit
    FragDataLocation(GLuint i) noexcept
        : index(i)
    {}

    constexpr
    operator auto() const noexcept {
        return index;
    }
};

template<>
class Optional<FragDataLocation> {
    GLint opt_index = -1;

public:
    constexpr
    Optional() noexcept = default;

    constexpr
    Optional(GLint opt_index) noexcept
        : opt_index(opt_index)
    {}

    constexpr
    auto operator*() const {
        return FragDataLocation(static_cast<GLuint>(opt_index));
    }

    constexpr
    operator bool() const noexcept {
        return opt_index >= 0;
    }
};

}
