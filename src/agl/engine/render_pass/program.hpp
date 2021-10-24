#pragma once

#include "render_pass.hpp"

#include <memory>

namespace agl::engine {

inline
auto& program(const RenderPass& rp) {
    return *rp.program;
}

inline
void assign_program(
    RenderPass& rp,
    const std::shared_ptr<eng::Program>& p)
{
    rp.program = p;
}

inline
auto& assign_program(
    RenderPass& rp,
    eng::Program&& p)
{
    return rp.program = std::make_shared<eng::Program>(std::move(p));
}

}
