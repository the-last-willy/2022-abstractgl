#pragma once

#include "qualifier.hpp"

namespace agl {

struct Level : Qualifier<GLint> {
    using Qualifier<GLint>::Qualifier;
};

}
