#pragma once

#include "proxy.hpp"

namespace agl::engine {

inline
uint32_t index(ConstFaceProxy ctp) {
    return ctp.index;
}

}
