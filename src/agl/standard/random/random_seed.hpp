#pragma once

#include <random>

namespace agl::standard {

inline
auto random_seed() {
    auto rd = std::random_device();
    return rd();
}

}
