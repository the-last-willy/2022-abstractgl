#pragma once

#include "load_materials.hpp"
#include "load_shapes.hpp"

#include <agl/engine/all.hpp>

#include <stb_image.h>
#include <stb_image_resize.h>
#include <tiny_obj_loader.h>

#include <filesystem>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace agl::format::wavefront {

struct Wavefront {
    tinyobj::attrib_t attrib;

    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
};

inline
Content load(
    const std::filesystem::path& obj_path,
    const std::filesystem::path& mtl_path)
{
    stbi_set_flip_vertically_on_load(true);

    tinyobj::ObjReaderConfig reader_config;
    reader_config.mtl_search_path = mtl_path.string();

    tinyobj::ObjReader reader;

    if (!reader.ParseFromFile(obj_path.string(), reader_config)) {
        if (!reader.Error().empty()) {
            std::cerr << "TinyObjReader: " << reader.Error();
        }
        throw std::runtime_error("TinyObjReader: Failed.");
    }

    if(!reader.Warning().empty()) {
        std::cout << "TinyObjReader: " << reader.Warning();
    }

    auto content = Content();

    load_materials(content, reader, mtl_path);
    load_shapes(content, reader);

    return content;
}

}
