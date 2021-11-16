#pragma once

#include <agl/image/all.hpp>

#include <stb_image.h>

#include <filesystem>
#include <stdexcept>

namespace agl::format::png {

inline
image::Image load(const std::path& file_path) {
    int x, y, n;
    auto data = stbi_load(file_path.string().c_str(), &x, &y, &n, 4);
    if(data != NULL) {

    } else {
        throw std::runtime_error();
    }
    stbi_image_free(data);
}

}
