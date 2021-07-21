#pragma once

#include "qualifier.hpp"

namespace agl {

template<typename Type>
struct BindingIndex : Qualifier<Type> {
    using Qualifier<Type>::Qualifier;

    // 'glGetAttributeLocation' returns a 'GLint'
    // ('-1' in case of failure)
    // but some functions take a 'GLuint' instead.
    // So this is the quick dirty workaround.
    operator AttributeIndex<GLuint>() const {
        return AttributeIndex<GLuint>(this->value);
    }
};

}
