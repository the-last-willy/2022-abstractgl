#pragma once

#include <agl/all.hpp>

#include <vector>

namespace eng {

struct Buffer {
    Buffer() = default;

    Buffer(const Buffer&) = delete;

    Buffer(Buffer&&) = default;

    ~Buffer() {
        delete_(opengl);
    }

    std::vector<std::byte> data = {};
    agl::Buffer opengl;
};

}
