add_library(glad)

target_sources(glad
PRIVATE
    glad/src/glad.c
)

target_include_directories(glad
PUBLIC
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/lib/glad/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
