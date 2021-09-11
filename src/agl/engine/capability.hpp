#pragma once

#include <agl/opengl/all.hpp>

#include <functional>

namespace eng {

struct Capability {
    agl::Capability capability;
    std::function<void()> on_enable = [](){};
};

inline
void enable(const Capability& c) {
    enable(c.capability);
    c.on_enable();
}

inline
void disable(const Capability& c) {
    disable(c.capability);
}

}
