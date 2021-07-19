#pragma once

#include "qualifier.hpp"

namespace agl {

struct Texture : Qualifier<GLuint> {
    using Qualifier<GLuint>::Qualifier;
};

}
