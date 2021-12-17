#pragma once

#include <cstddef>

namespace agl::common {

template<typename Element>
struct Size {
    std::size_t value;

    operator std::size_t() const noexcept {
        return value;
    }

    operator Size<std::byte>() const noexcept {
        return Size<std::byte>(sizeof(Element) * value);
    }
};

}