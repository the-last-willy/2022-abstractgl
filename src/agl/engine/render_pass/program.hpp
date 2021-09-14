#pragma once

#include "render_pass.hpp"

namespace agl::engine {

inline
auto& program(const RenderPass& rp) {
    return *rp.program;
}

}
