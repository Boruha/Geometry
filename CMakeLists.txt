cmake_minimum_required(VERSION 3.15)

set(TARGET_NAME Geometry)
project(${TARGET_NAME})

add_library(${TARGET_NAME})

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
file(GLOB HPP_FILES ${INCLUDE_DIR}/*.hpp)
file(GLOB CPP_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

message("${INCLUDE_DIR}")
message("${CMAKE_SOURCE_DIR}/src")

target_include_directories(${TARGET_NAME} 
    PUBLIC 
        ${INCLUDE_DIR})
        
target_sources(${TARGET_NAME}
    PUBLIC
        ${HPP_FILES}
    PRIVATE
        ${CPP_FILES})
