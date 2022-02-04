add_library(abstractgl INTERFACE)

target_include_directories(abstractgl
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:src>
)

add_library(abstractgl::abstractgl ALIAS abstractgl)

install(
    TARGETS abstractgl
    EXPORT  abstractglTargets
)

install(
    EXPORT      abstractglTargets
    DESTINATION lib/cmake/abstractgl
    FILE        abstractglTargets.cmake
    NAMESPACE   abstractgl::
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    abstractglConfigVersion.cmake
    VERSION       0.2
    COMPATIBILITY AnyNewerVersion)

install(
    FILES 
        ../cmake/abstractglConfig.cmake 
        ${CMAKE_CURRENT_BINARY_DIR}/abstractglConfigVersion.cmake
    DESTINATION 
        lib/cmake/abstractgl
)
