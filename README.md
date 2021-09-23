*Nothing is anywhere close to be in a remotely finished state. But it's going forward.*

AbstractGL is a collection of libraries for computer graphics (supporting only OpenGL at the moment).

I'm aware of how immeasurably ambitious this projects might appears.
However, I'm not trying to rivalize with anybody.
It's meant to be used in my other projects (as I don't want to redo things between projects) and it grows depending on the requirements of these.

If you like anything you see, you can just blatantly steal it as it licenced under MIT ;)
But it would be greatly appreciated if you chose to contribute instead.

Many modules are independent.
You need only to include what you wish to use.

There is currently not a spec of testing around.
I can only say that it seems to work in some projects (but that's not testing).
Please find it in your heart to forgive me.

# Engine module

The engine module is currently a renderer and only supports OpenGL as a backend.

It is able to fully support glTF files, that is:
- Textures and samplers
- PBR pipeline (metallic/roughness, normal mapping, emissivity, ambient occusion)
- Node hierarchies
- Keyframe based animations
- Vertex skinning
(In fact, it's just missing morphing.)

Lighting (directional, spot and omni) and shadow mapping is supported.

Deferred rendering can be easily supported as well.

Also, automatic shader plumbing and uploading.

## Long-term goals

To be a full fledged engine with events, physics (?), scripting (?), sounds (?).

To be multi-platform and able to work with any graphics backend.

Support for ray-tracing based techniques (why not ?).

## TODO

- Abstract it away from OpenGL
- Data-oriented
- Move it into its own project
- [glTF](https://github.com/KhronosGroup/glTF-Sample-Models) conformance table

# File format modules

Currently handled file formats (some using external libraries):
- glTF 2.0  (.gltf)
- OFF (.off)
- Wavefront (.mtl, .obj)

## TODO

- FBX support
- Retrieve metadata

# GLSL module

The GLSL module provides GLSL types and functions on CPU side.

## Long-term goals

To provide a symbolic representation of GLSL code.

## TODO

- Distinguish from the OpenGL module
- Use the maths module

# GLSL compiler module

The GLSL shading language is intended for graphics vendors as well as programmers.
Therefore it is minimal and lacking many useful abstractions.
This module offers an additionnal set of features for the GLSL language by providing a compiler from extended GLSL to GLSL.
Such as:
- #include directive
- That's it... As of now.

## TODO

- Distinguish from the engine module

# Maths module

The maths module provides linear algebra (matrices) and quaternions.

## TODO

- Distinguish from the GLSL module
- Use GLM internally

# OpenGL module

The OpenGL module wraps the aging OpenGL C API and provides a modern C++ interface.

**Abstract.**
Many parameters can be grouped together in relevant abstractions therefore making function signatures simpler.
There is also no need to have verbose function names so these have been made shorter as well (nice side effect a few items below).

**Disambiguation.**
The OpenGL API has become *bloated* and *redundant* over the years.
It is also the case that advanced users are sometimes not aware of newer functions that they should prefer.
Therefore the API can be reduced to a sane subset and many functions can be deprecated.

**Genericity.**
Writing generic code with the OpenGL API is not possible.
However it is with this module.

**Strong typing.**
The OpenGL API makes it very easy to pass the wrong arguments to a function.
That's because it is thought in terms of data representation (well, it's C).
Therefore OpenGL types have been encapsulated based on semantics instead of representation in costless way.

**Why not Vulkan ?** 
In a perfect world, everybody would be using Vulkan since all vendors would support it and there would be tons of tutorials about it.
However, that's not the case.
OpenGL is still relevant today and many beginners start from there.
So we might as well make a better experience out of OpenGL.

## Long-term goals

Support older versions of OpenGL (feature emulation) ?

# Compatibility

Required:
- Support for C++20.
- Support for OpenGL 4.5 is required.

Development has been done under MSVC 19.29.

# Installation

This project uses submodules.

No OpenGL loader is included for the OpenGL module.
You will need to add one yourself to your own project (see [glad](https://github.com/Dav1dde/glad) or [FreeGLUT](http://freeglut.sourceforge.net/)) and include it before the  

# Showcase

## Screenshots

Sponza scene with Blinn-Phong lighting and omni directional lighting:
![image](https://user-images.githubusercontent.com/84744335/134546040-b61752c6-8218-4554-b255-b26bd9249f5d.png)

PBR test scene:
![image](https://user-images.githubusercontent.com/84744335/134546239-ae93ddfa-c602-4a05-ad89-de2cb3a2f13c.png)

Damaged Helmet with PBR pipeline (metallic/roughness, emissivity, normal mapping, ambient occlusion).
![image](https://user-images.githubusercontent.com/84744335/134546119-9f0657eb-e93d-43c1-8912-9494c8bf6290.png)

Sponza scene with PBR pipeline:
![image](https://user-images.githubusercontent.com/84744335/134546077-153f1510-33e1-4e7c-92be-184b5bd985c0.png)

Computation of normals with Laplacian approximation:
![image](https://user-images.githubusercontent.com/84744335/134546328-603c2189-b8da-46e1-912c-5d2af42a5033.png)

TODO: Add a video cuz you can't take a screenshot of an animation.

## Projects

Another project of mine: [id3d](https://github.com/the-last-willy/id3d).
