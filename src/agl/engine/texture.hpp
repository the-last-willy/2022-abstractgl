#pragma once

#include <agl/opengl/all.hpp>

#include <optional>

namespace eng {

struct Texture {
    std::optional<agl::Sampler> sampler = std::nullopt;
    agl::Texture texture = {};
};

}
