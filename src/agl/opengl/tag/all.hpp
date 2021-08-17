#pragma once

#include "names.hpp"
#include "shader_types.hpp"

namespace agl {

struct None {};
constexpr auto none = None();

// Buffers.

struct ColorTag {};
constexpr auto color_tag = ColorTag();

struct DepthTag {};
constexpr auto depth_tag = DepthTag();

struct StencilTag {};
constexpr auto stencil_tag = StencilTag();

}
