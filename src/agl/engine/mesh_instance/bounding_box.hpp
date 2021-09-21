#pragma once

#include "mesh_instance.hpp"

#include "agl/engine/bounding_box/bounding_box.hpp"

#include <stdexcept>

namespace agl::engine {

inline
BoundingBox bounding_box(const MeshInstance& mi) {
    auto it = mi.uniforms.find("mvp_transform");
    if(it != end(mi.uniforms)) {
        if(auto& t = dynamic_cast<const agl::Uniform<agl::Mat4>&>(*it)) {
            auto& a = mesh(mi).attributes
            return BoundingBox();
        }
    } else {
        throw std::logic_error("Missing mesh instance transform.");
    }
}

}
