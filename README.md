*WORK IN PROGRESS*

AbstractGL is a collection of libraries for computer graphics.

# Engine module

# GLSL module

## TODO

- Distinguish from the OpenGL module.
- Use GLM internally.

# GLSL compiler module

The GLSL shading language is intended for graphics vendors as well as programmers.
Therefore it is minimal and lacking many useful abstractions.
This module offers an additionnal set of features for the GLSL language by providing a compiler from extended GLSL to GLSL.
Such as:
- #include directive

## TODO

- Distinguish from the engine module

# Maths module



# OpenGL module

**Disambiguation.** 

**Genericity.**

**Strong typing.** 

# Compatibility

Support for OpenGL 4.5 is required.

Development has been done under MSVC 19.29.

# Installation

This project uses submodules.

No OpenGL loader is included for the OpenGL module.
You will need to add one yourself to your own project (see [glad](https://github.com/Dav1dde/glad) or [FreeGLUT](http://freeglut.sourceforge.net/)) and include it before the  

AbstractGL is an OpenGL API wrapper aiming at facilitating learning and writing modern OpenGL.

This aim is achieved through the following:

**Deprecating older functions.**
The OpenGL core profile presents 100+ functions which can be very daunting to beginners.
A lot of these functions are redundant.
It is also the case that many advanced users are not aware of newer functions that they should instead use.

**Better typing.**

**Better interfaces.** 

**GLSL types.** 

**Utilitaties.** 

**Use what you want.**


