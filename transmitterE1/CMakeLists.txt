
# Author: Arhur Cadore M. Barcella
# GitHub: arthurcadore
# This file contains the CMakeLists.txt of the project.
# This code is responsible for compiling the project.

cmake_minimum_required(VERSION 3.13)
project(transmitterE1)

set(CMAKE_CXX_STANDARD 11)
include_directories(.)

add_executable(transmitterE1 main.cpp generator.cpp writer.cpp)

add_custom_target(run
    COMMAND transmitterE1
    DEPENDS transmitterE1
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)