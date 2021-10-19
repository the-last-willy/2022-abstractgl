#pragma once

#include <agl/engine/all.hpp>

namespace agl::format::wavefront {

struct Content {
    std::vector<std::shared_ptr<eng::Material>> materials;
    std::vector<std::shared_ptr<eng::Mesh>> meshes;
    std::vector<std::shared_ptr<agl::engine::TriangleMesh>> tmeshes;
};

}
