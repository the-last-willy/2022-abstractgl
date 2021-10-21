#pragma once

#include <agl/opengl/all.hpp>

namespace agl::engine {

struct Geometry {
    // Faces.

    uint32_t face_count = 0;

    std::vector<uint32_t> face_material_ids;

    // Vertices.

    uint32_t vertex_count = 0;

    std::vector<uint32_t> vertex_material_ids;
    std::vector<agl::Vec3> vertex_normals;
    std::vector<agl::Vec3> vertex_positions;
    std::vector<agl::Vec2> vertex_texcoords;
};

}
