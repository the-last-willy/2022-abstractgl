#pragma once

#include "agl/opengl/tag/shader_types.hpp"

namespace agl {

class ShaderType {
    GLenum value;

public:
    explicit
    ShaderType(GLenum e) noexcept
        : value(e)
    {}

    ShaderType(ComputeShaderTag) noexcept
        : ShaderType(ComputeShaderTag::enum_)
    {}

    ShaderType(FragmentShaderTag) noexcept
        : ShaderType(FragmentShaderTag::enum_)
    {}

    ShaderType(VertexShaderTag) noexcept
        : ShaderType(VertexShaderTag::enum_)
    {}

    operator GLenum() const noexcept {
        return value;
    }
};

}
