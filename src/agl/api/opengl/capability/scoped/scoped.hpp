#pragma once

#include "type/enabled_capability.hpp"
#include "scoped_capability.hpp"

namespace agl::opengl {

inline
ScopedCap scoped(EnabledCap cap) {
    return ScopedCap(cap);
}

}
