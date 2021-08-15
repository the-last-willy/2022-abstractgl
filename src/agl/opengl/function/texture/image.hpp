#pragma once

#include "agl/opengl/qualifier/Level.hpp"
#include "agl/opengl/name/all.hpp"
#include "agl/opengl/qualifier/height.hpp"
#include "agl/opengl/qualifier/width.hpp"

#include <cstddef>
#include <span>

namespace agl {

inline
void image(
    Texture t,
  	Level l,
  	GLint xoffset,
  	GLint yoffset,
  	Width w,
  	Height h,
  	GLenum format,
  	GLenum type,
  	std::span<const std::byte> pixels)
{
    glTextureSubImage2D( 
        t,
        l,
        xoffset,
        yoffset,
        w,
        h,
        format,
        type,
        data(pixels));
}

inline
void image(
    Texture t,
  	Width w,
  	Height h,
  	GLenum format,
  	GLenum type,
  	std::span<const std::byte> pixels)
{
    image( 
        t,
        Level(0),
        0,
        0,
        w,
        h,
        format,
        type,
        pixels);
}

}
