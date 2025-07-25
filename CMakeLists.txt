cmake_minimum_required(VERSION 3.16)
project(Core3D VERSION 1.0.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_EXAMPLES "Build example applications" ON)
option(CORE3D_USE_OPENGL "Enable OpenGL backend support" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

if (BUILD_EXAMPLES)
    MESSAGE(STATUS "Building examples is enabled")
    add_subdirectory(examples)
endif()