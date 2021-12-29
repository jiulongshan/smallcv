cmake_minimum_required(VERSION 3.15)

project(smallcvtest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
option(SMALLCV_IMAGEIO "Image I/O?" ON)

include_directories(
    ../compile/install/include
)

link_directories(
    ../compile/install/lib
)

add_executable(basic_example
  ${CMAKE_SOURCE_DIR}/example.cpp
)
target_link_libraries(basic_example smallcv)