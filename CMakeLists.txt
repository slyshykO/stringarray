cmake_minimum_required(VERSION 3.11)

project(srtingarray C CXX)

set(SRC_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/stringarray/stringarray.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/examples/src/main.cpp
    )

add_executable(example ${SRC_LIST})

target_include_directories(example
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/stringarray>
    )
