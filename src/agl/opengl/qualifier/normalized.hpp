#pragma once

#include "qualifier.hpp"

namespace agl {

struct Normalized : Qualifier<GLboolean> {
    using Qualifier<GLboolean>::Qualifier;
};

}
