#pragma once

#include "program.hpp"
#include "render_pass.hpp"

#include "agl/engine/mesh.hpp"
#include "agl/engine/primitive.hpp"

namespace agl::engine {

inline
void subscribe(RenderPass& rp, const eng::Primitive& pi, VertexArray va) {
    auto& po = program(rp);
    if(pi.indices.buffer) {
        element_buffer(va, pi.indices.buffer->opengl);
    }
    for(int i = 0; i < agl::active_attributes(po.program); ++i) {
        auto aa = agl::active_attrib(po.program, agl::AttributeIndex(i));
        auto ai = attribute_location(po.program, aa.name.c_str());
        auto bi = agl::BindingIndex<GLuint>(i);
        attribute_binding(va, ai, bi);
        auto it = pi.attributes.find(aa.name);
        if(it != end(pi.attributes)) {
            auto& accessor = it->second;
            attribute_format(
                va, ai,
                accessor.component_count,
                accessor.component_type,
                accessor.normalized,
                agl::Offset<GLuint>(0));
            vertex_buffer(
                va, bi,
                accessor.buffer->opengl,
                agl::Offset<GLintptr>(
                    accessor.buffer_view_byte_offset.value
                    + accessor.byte_offset.value),
                accessor.buffer_view_byte_stride);
            enable(va, ai);
        } else {
            // ?
        }
    }
}

inline
void subscribe(RenderPass& rp, const std::shared_ptr<eng::Mesh>& m) {
    auto& s = rp.subscriptions.emplace_back();
    s.mesh = m;
    for(auto& p : m->primitives) {
        auto va = s.vertex_arrays.emplace_back(create(agl::vertex_array_tag));
        subscribe(rp, *p, va);
    }
}

}
