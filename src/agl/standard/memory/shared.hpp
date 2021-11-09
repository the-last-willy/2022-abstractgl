#pragma once

#include <memory>

namespace agl::standard {

template<typename T>
std::shared_ptr<T> shared(const T&) {
    static_assert(
        false,
        "agl::standard::shared: Rvalue expected.");
}

template<typename T>
std::shared_ptr<T> shared(T&& t) {
    return std::make_shared<T>(std::move(t));
}

}
