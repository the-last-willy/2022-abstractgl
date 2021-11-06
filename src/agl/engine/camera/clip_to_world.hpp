#pragma once

#include "camera.hpp"
#include "eye_to_clip.hpp"
#include "world_to_eye.hpp"

namespace agl::engine {

inline
auto clip_to_world(const eng::Camera& c) {
    return inverse(eye_to_clip(c) * world_to_eye(c));
}

}
