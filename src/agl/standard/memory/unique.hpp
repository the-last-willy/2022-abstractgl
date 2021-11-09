#pragma once

#include <memory>

namespace agl::standard {

template<typename T>
std::shared_ptr<T> unique(const T&) {
    static_assert(
        false,
        "agl::standard::unique: Rvalue expected.");
}

template<typename T>
std::shared_ptr<T> unique(T&& t) {
    return std::make_unique<T>(std::move(t));
}

}
