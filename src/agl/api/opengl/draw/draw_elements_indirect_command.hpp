#pragma once

namespace agl::opengl {

struct DrawElementsIndirectCommand {
    GLuint count = 0;
    GLuint instanceCount = 0;
    GLuint firstIndex = 0;
    GLuint baseVertex = 0;
    GLuint baseInstance = 0;
};

}
