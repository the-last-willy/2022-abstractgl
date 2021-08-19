#pragma once

#include "names.hpp"
#include "none.hpp"
#include "shader_types.hpp"

namespace agl {

// Buffers.

struct ColorTag {};
constexpr auto color_tag = ColorTag();

struct DepthTag {};
constexpr auto depth_tag = DepthTag();

struct StencilTag {};
constexpr auto stencil_tag = StencilTag();

}
