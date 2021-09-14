#pragma once

#include "program.hpp"
#include "render_pass.hpp"

namespace agl::engine {

inline
void render(const RenderPass& rp) {
    // bind(program(rp));
    use(program(rp).program);
    { // Upload uniforms.
        for(auto& [name, value] : rp.uniforms) {
            auto ul = uniform_location(program(rp).program, name.c_str());
            if(ul) {
                value->set(program(rp).program, *ul);
            }
        }
    }
    { // Draw calls.
        for(auto& s : rp.subscriptions) {
            // for(std::size_t i = 0; i < size(s.vertex_arrays); ++i) {
            //     bind(s.vertex_arrays[i]);
            //     eng::render(*s.mesh->primitives[i]);
            // }
            for(auto& p : s.mesh->primitives) {
                bind(p->vertex_array);
                eng::render(*p);
            }
        }
    }
    // unbind(program(rp));
}

}
