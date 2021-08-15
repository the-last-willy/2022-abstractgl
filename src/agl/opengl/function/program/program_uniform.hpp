#pragma once

#include "agl/opengl/name/all.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"

namespace agl {

inline
void uniform( 
    Program p,
  	UniformIndex ui,
  	float value)
{
    glProgramUniform1f(
        p,
        ui,
        value);
}

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

