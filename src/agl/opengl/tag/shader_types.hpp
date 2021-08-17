#pragma once

#include <concepts>

namespace agl {

struct ComputeShaderTag {
    static constexpr GLenum enum_ = GL_COMPUTE_SHADER;
};
constexpr auto compute_shader_tag = ComputeShaderTag();

struct FragmentShaderTag {
    static constexpr GLenum enum_ = GL_FRAGMENT_SHADER;
};
constexpr auto fragment_shader_tag = FragmentShaderTag();

struct VertexShaderTag {
    static constexpr GLenum enum_ = GL_VERTEX_SHADER;
};
constexpr auto vertex_shader_tag = VertexShaderTag();

}
