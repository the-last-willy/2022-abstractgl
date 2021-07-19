#pragma once

#include "parameter.hpp"

namespace agl {

struct Height : Parameter<GLsizei> {
    using Parameter<GLsizei>::Parameter;
};

}
