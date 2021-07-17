cmake_minimum_required(VERSION 3.19)
project(abstract_gl)

set(CMAKE_CXX_STANDARD 20)

add_library(abstract_gl INTERFACE)

target_include_directories(abstract_gl
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
