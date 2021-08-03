#pragma once

#include "agl/opengl/qualifier/program.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"

namespace agl {

inline
void uniform( 
    Program p,
  	UniformIndex<GLint> ui,
  	int value)
{
    glProgramUniform1i(
        p,
        ui,
        value);
}
    

}

