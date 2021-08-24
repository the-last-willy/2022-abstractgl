#pragma once

#include <glad/glad.h>

namespace agl {

enum class ProgramParameter : GLenum {
    // GL_ACTIVE_ATOMIC_COUNTER_BUFFERS,
    active_attributes = GL_ACTIVE_ATTRIBUTES,
    active_attribute_max_length = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
    active_uniforms = GL_ACTIVE_UNIFORMS,
    // GL_ACTIVE_UNIFORM_BLOCKS,
    // GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH,
    active_uniform_max_length = GL_ACTIVE_UNIFORM_MAX_LENGTH,
    // GL_ATTACHED_SHADERS,
    // GL_COMPUTE_WORK_GROUP_SIZE,
    // GL_GEOMETRY_INPUT_TYPE, 
    // GL_GEOMETRY_OUTPUT_TYPE,
    // GL_GEOMETRY_VERTICES_OUT,
    // GL_INFO_LOG_LENGTH,
    link_status = GL_LINK_STATUS,
    // GL_PROGRAM_BINARY_LENGTH,
    // GL_TRANSFORM_FEEDBACK_BUFFER_MODE,
    // GL_TRANSFORM_FEEDBACK_VARYINGS,
    // GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH,
    // GL_VALIDATE_STATUS,
};

}
