# Credits to 'https://dominikberner.ch/cmake-interface-lib/'.

cmake_minimum_required(VERSION 3.19)
project(AbstractGL
    VERSION 0.1.0
)

add_subdirectory(lib)

include(GNUInstallDirs)

add_library(${PROJECT_NAME} INTERFACE)

# Adding the install interface generator expression makes sure that the include
# files are installed to the proper location (provided by GNUInstallDirs)
target_include_directories(${PROJECT_NAME}
INTERFACE
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(${PROJECT_NAME}
    INTERFACE cxx_std_20
)

target_link_libraries(${PROJECT_NAME}
INTERFACE
    glad
)

# enable_testing()
# add_subdirectory(test)

# locations are provided by GNUInstallDirs
install(
    TARGETS ${PROJECT_NAME} glad
    EXPORT ${PROJECT_NAME}_Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

install(
    EXPORT ${PROJECT_NAME}_Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

install(
    FILES
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/lib/glad/include/glad
    DESTINATION include
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/lib/glad/include/KHR
    DESTINATION include
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/src/agl
    DESTINATION include
)

add_executable(test-sandbox test/sandbox.cpp)

target_link_libraries(test-sandbox
PRIVATE
    AbstractGL
)
