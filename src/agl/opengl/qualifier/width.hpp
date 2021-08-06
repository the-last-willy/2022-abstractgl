#pragma once

#include "parameter.hpp"

namespace agl {

struct Width : Parameter<GLsizei> {
    using Parameter<GLsizei>::Parameter;
};

}
