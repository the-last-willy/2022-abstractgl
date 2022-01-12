#pragma once

#include <compare>

namespace agl::opengl {

struct DrawElementsIndirectCommand {
    // Number of indices (not primitives).
    GLuint count = 0;
    // '1' seems to be the least surprising value,
    // when not specified, a single instance is drawn.
    GLuint instanceCount = 1;
    GLuint firstIndex = 0;
    GLuint baseVertex = 0;
    GLuint baseInstance = 0;
};

inline
std::strong_ordering operator<=>(
    const DrawElementsIndirectCommand& c0,
    const DrawElementsIndirectCommand& c1)
{
    auto cmp = c0.baseInstance <=> c1.baseInstance;
    if(cmp != 0) {
        return cmp;
    }
    cmp = c0.instanceCount <=> c1.instanceCount;
    if(cmp != 0) {
        return cmp;
    }
    cmp = c0.firstIndex <=> c1.firstIndex;
    if(cmp != 0) {
        return cmp;
    }
    cmp = c0.baseVertex <=> c1.baseVertex;
    if(cmp != 0) {
        return cmp;
    }
    return c0.count <=> c1.count;
}

}
