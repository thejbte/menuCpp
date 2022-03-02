#https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# set the project name
project(athmost)

# set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_VERBOSE_MAKEFILE FALSE)
set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_FLAGS -fconcepts-ts)

# add the executable
add_executable(athmost main.cpp data/data.cpp ui/ui.cpp)

#Include directories
target_include_directories(athmost PUBLIC "${PROJECT_SOURCE_DIR}/single_include/nlohmann" "${PROJECT_SOURCE_DIR}/ui" "${PROJECT_SOURCE_DIR}/app")

