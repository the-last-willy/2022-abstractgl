#pragma once

#include "geometry/all.hpp"

#include "topology/all.hpp"

#include "agl/opengl/all.hpp"

#include <optional>
#include <vector>

namespace agl::engine {

struct TriangleMesh {
    Geometry geometry;
    Topology topology = Topology(3);

    std::vector<uint32_t> indices;

    uint32_t vertex_per_face = 3;

    std::vector<uint32_t> material_ids;
    std::vector<agl::Vec3> normals;
    std::vector<agl::Vec3> positions;
    std::vector<agl::Vec2> texcoords;
};

}
