#pragma once

namespace agl {

struct BufferTag {};
constexpr auto buffer_tag = BufferTag();

struct FramebufferTag {};
constexpr auto framebuffer_tag = FramebufferTag();

struct ProgramTag {};
constexpr auto program_tag = ProgramTag();

struct SamplerTag {};
constexpr auto sampler_tag = SamplerTag();

struct ShaderTag {};
constexpr auto shader_tag = ShaderTag();

struct TextureTag {};
constexpr auto texture_tag = TextureTag();

struct VertexArrayTag {};
constexpr auto vertex_array_tag = VertexArrayTag();

}
