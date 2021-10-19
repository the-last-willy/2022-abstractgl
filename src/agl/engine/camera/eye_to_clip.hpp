#pragma once

#include "camera.hpp"
#include "eye_to_world.hpp"

namespace agl::engine {

inline
auto eye_to_clip(const eng::Camera& c) {
    if(auto op = std::get_if<agl::engine::OrthographicProjection>(&c.projection)) {
        return transform(*op);
    } else if(auto pp = std::get_if<eng::PerspectiveProjection>(&c.projection)) {
        return transform(*pp);
    }
    throw std::runtime_error("NOT IMPLEMENTED.");
}

}
