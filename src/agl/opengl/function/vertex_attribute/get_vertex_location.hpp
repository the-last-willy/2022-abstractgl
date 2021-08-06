#pragma once

#include "agl/opengl/qualifier/attribute_index.hpp"
#include "agl/opengl/qualifier/cstring.hpp"
#include "agl/opengl/names.hpp"

namespace agl {

inline
AttributeIndex<GLint> get_attrib_location(Program p, cstring name) {
    return AttributeIndex<GLint>(glGetAttribLocation(
            static_cast<GLuint>(p),
            name));
}

inline
AttributeIndex<GLint> attribute_location(Program p, cstring name) {
    return get_attrib_location(p, name);
}

}
