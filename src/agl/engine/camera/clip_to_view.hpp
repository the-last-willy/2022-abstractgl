#pragma once

#include "camera.hpp"
#include "eye_to_clip.hpp"
#include "world_to_eye.hpp"

namespace agl::engine {

inline
auto clip_to_view(const eng::Camera& c) {
    return inverse(eye_to_clip(c));
}

}
