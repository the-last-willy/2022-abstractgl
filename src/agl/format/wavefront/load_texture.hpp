#pragma once

#include <agl/engine/all.hpp>

#include <stb_image.h>
#include <stb_image_resize.h>

namespace agl::format::wavefront {

inline
auto load_texture(std::string filepath, int) {

    int w, h, n;
    unsigned char *data = stbi_load(filepath.c_str(), &w, &h, &n, 0);
    if(data == NULL) {
        throw std::runtime_error("stb_image: Failure.");
    }

    // auto dw = w / factor;
    // auto dh = w / factor;
    // auto downsampled = std::vector<unsigned char>(n * dw * dh);

    // auto r = stbir_resize_uint8(
    //     data, w, h, 0,
    //     downsampled.data(), dw, dh, 0,
    //     n);
    // if(r == 0) {
    //     throw std::runtime_error("stb_image_resize: Failure.");
    // }

    auto t = agl::create(agl::TextureTarget::_2d);
    GLenum base_internal_format = 0;
    GLenum pixel_data_type = 0;
    GLenum sized_internal_format = 0;
    if(n == 3) {
        base_internal_format = GL_RGB;
        pixel_data_type = GL_UNSIGNED_BYTE;
        sized_internal_format = GL_RGB8;
    } else if(n == 4) {
        base_internal_format = GL_RGBA;
        pixel_data_type = GL_UNSIGNED_BYTE;
        sized_internal_format = GL_RGBA8;
    } else {
        throw std::runtime_error("Invalid texture format.");
    }
    auto level_count = static_cast<GLsizei>(
        std::floor(std::log2(std::max(h, w))) + 1);
    agl::storage(
            t, level_count, sized_internal_format,
            agl::Width(w), agl::Height(h));
    agl::image(
        t, agl::Width(w), agl::Height(h),
        base_internal_format, pixel_data_type,
        std::as_bytes(std::span(data, w * h * n)));
    agl::generate_mipmap(t);

    stbi_image_free(data);

    auto et = eng::Texture();
    et.texture = t;
    return et;
}

}
