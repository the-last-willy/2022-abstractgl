#pragma once

#include <agl/opengl/all.hpp>

namespace agl::engine {

struct Geometry {
    uint32_t vertex_count = 0;

    std::vector<agl::Vec3> vertex_material_ids;
    std::vector<agl::Vec3> vertex_normals;
    std::vector<agl::Vec3> vertex_positions;
    std::vector<agl::Vec3> vertex_texcoords;
};

}
