#pragma once

#include <map>

namespace agl::standard {

template<typename... M> constexpr
auto& front(const std::map<M...>& m) {
    return *begin(m);
}

}
