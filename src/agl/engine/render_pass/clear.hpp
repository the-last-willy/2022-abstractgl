#pragma once

#include "render_pass.hpp"

namespace agl::engine {

inline
void clear(RenderPass& rp) {
    rp.subscriptions.clear();
}

}
