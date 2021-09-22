#pragma once

#include "mesh.hpp"
#include "mesh_instance.hpp"

#include "agl/engine/bounding_box/bounding_box.hpp"

#include <stdexcept>

namespace agl::engine {

inline
BoundingBox bounding_box(const MeshInstance& mi) {
    auto it = mi.uniforms.find("mvp_transform");
    if(it != end(mi.uniforms)) {
        auto& t = dynamic_cast<const eng::Uniform<agl::Mat4>&>(*it->second);
        auto& m = mesh(mi);
        return BoundingBox(m.bb_min, m.bb_max, eng::Transform(t.value));
    } else {
        throw std::logic_error("Missing mesh instance transform.");
    }
}

}
