#pragma once

#include "type/enabled_capability.hpp"

namespace agl::opengl {

EnabledCap Enable(GLenum cap) {
    glEnable(cap);
    return cap;
}

}
