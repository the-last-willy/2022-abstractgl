#pragma once

#include "agl/opengl/names.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"

namespace agl {

inline
void uniform( 
    Program p,
  	UniformIndex ui,
  	int value)
{
    glProgramUniform1i(
        p,
        ui,
        value);
}
    

}

