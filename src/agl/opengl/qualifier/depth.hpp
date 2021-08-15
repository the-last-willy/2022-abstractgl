#pragma once

#include "parameter.hpp"

namespace agl {

struct Depth : Parameter<GLsizei> {
    using Parameter<GLsizei>::Parameter;
};

}
