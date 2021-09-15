#pragma once

#include "mesh_instance.hpp"

#include "agl/engine/program.hpp"

namespace agl::engine {

inline
void upload_to(const MeshInstance& mi, const eng::Program& p) {
    for(auto& [name, value] : mi.uniforms) {
        auto ul = uniform_location(p.program, name.c_str());
        if(ul) {
            value->set(p.program, *ul);
        }
    }
}

}
