#pragma once

#include "camera.hpp"

namespace agl::engine {

inline
auto rotation(const eng::Camera& c) {
    return rotation(c.view);
}

}
