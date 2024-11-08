cmake_minimum_required(VERSION 3.15)

set(TARGET_NAME Geometry)
project(${TARGET_NAME})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include(compiler_options)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
file(GLOB HPP_FILES ${INCLUDE_DIR}/*.hpp)
file(GLOB CPP_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_subdirectory(test)