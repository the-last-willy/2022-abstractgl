#pragma once

#include "qualifier.hpp"

namespace agl {

struct TextureUnit : Qualifier<GLuint> {
    using Qualifier<GLuint>::Qualifier;
};

}
