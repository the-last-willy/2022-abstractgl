#pragma once

#include "camera.hpp"
#include "eye_to_clip.hpp"
#include "world_to_eye.hpp"

namespace agl::engine {

inline
auto world_to_clip(const eng::Camera& c) {
    return eye_to_clip(c) * world_to_eye(c);
}

}
