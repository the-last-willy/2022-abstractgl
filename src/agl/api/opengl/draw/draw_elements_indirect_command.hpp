#pragma once

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

}
