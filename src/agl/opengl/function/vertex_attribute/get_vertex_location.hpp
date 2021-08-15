#pragma once

#include "agl/opengl/qualifier/attribute_index.hpp"
#include "agl/opengl/qualifier/czstring.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
AttributeIndex<GLint> get_attrib_location(Program p, czstring name) {
    return AttributeIndex<GLint>(glGetAttribLocation(
            static_cast<GLuint>(p),
            name));
}

inline
AttributeIndex<GLint> attribute_location(Program p, czstring name) {
    return get_attrib_location(p, name);
}

}
