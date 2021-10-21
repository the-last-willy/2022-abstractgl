#pragma once

#include "accessor.hpp"
#include "material.hpp"

#include <memory>
#include <optional>
#include <stdexcept>
#include <string>

namespace eng {

struct Primitive {
    std::map<std::string, std::shared_ptr<eng::Accessor>> attributes = {};

    std::shared_ptr<Material> material = {};

    std::shared_ptr<eng::Accessor> indices = std::make_shared<eng::Accessor>();

    agl::DrawMode draw_mode = agl::DrawMode::triangles;
    agl::DrawType draw_type;
    
    std::size_t offset = 0;
    agl::Count<GLsizei> primitive_count = agl::Count<GLsizei>(0);
};

inline
void unbind(const Primitive& p) {
    if(p.material) {
        unbind(*p.material);
    }
}

// HEAVILY BROKEN
// PROBABLY BECAUSE COUNT ISN'T PROPERLY SET IN SOME ACCESSORS.
/*
inline
void render(const Primitive& p) {
    if(p.indices->count == 0) {
        agl::draw_arrays(
            p.draw_mode,
            agl::Offset<GLint>(static_cast<GLint>(p.offset)),
            p.primitive_count);
    } else {
        agl::draw_elements(
            p.draw_mode,
            p.primitive_count,
            p.draw_type,
            agl::Offset<GLintptr>(p.offset));
    }
}
*/

inline
void render(const Primitive& p, agl::VertexArray va) {
    if(agl::element_array_buffer_binding(va)) {
        agl::draw_elements(
            p.draw_mode,
            p.primitive_count,
            p.draw_type,
            agl::Offset<GLintptr>(p.offset));
    } else {
        agl::draw_arrays(
            p.draw_mode,
            agl::Offset<GLint>(static_cast<GLint>(p.offset)),
            p.primitive_count);
    }
}

}
