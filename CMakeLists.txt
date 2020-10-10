# Preamble
cmake_minimum_required(VERSION 3.17)
project(The_Ray_Tracer_Challenge)
enable_testing()

# Project wide setup
# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Externally provided content
# add_subdirectory(dependencies)

# Main targets built by this project
add_subdirectory(src)

# Demo programs using rtc library
add_subdirectory(examples)

# Things typically only needed if we are the top level project
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(tests)
    # add_subdirectory(packaging)
endif()
