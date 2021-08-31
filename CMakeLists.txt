cmake_minimum_required(VERSION 3.19)

project(abstractgl VERSION 0.1.0)

add_library(abstractgl INTERFACE)

target_include_directories(abstractgl
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
