#pragma once

namespace agl::tag {

struct Buffer {};
constexpr auto buffer = Buffer();

struct Framebuffer {};
constexpr auto framebuffer = Framebuffer();

struct Program {};
constexpr auto program = Program();

struct Sampler {};
constexpr auto sampler = Sampler();

struct Shader {};
constexpr auto shader = Shader();

struct Texture {};
constexpr auto texture = Texture();

struct VertexArray {};
constexpr auto vertex_array = VertexArray();

}
