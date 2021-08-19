#pragma once

namespace agl {

struct None {
    operator auto() const noexcept {
        return GL_NONE;
    }
};

constexpr auto none = None();

}
