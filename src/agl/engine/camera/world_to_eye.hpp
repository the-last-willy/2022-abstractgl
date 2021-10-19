#pragma once

#include "camera.hpp"
#include "eye_to_world.hpp"

namespace agl::engine {

inline
auto world_to_eye(const eng::Camera& c) {
    return inverse(eye_to_world(c));
}

}
