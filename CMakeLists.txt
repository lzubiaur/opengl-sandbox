cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

set(PROJECT_NAME "OpenGLsandbox")
set(RUNTIME_NAME "opengl")
# set(BUNDLE_NAME  "")

project(${PROJECT_NAME} C CXX)

# TODO GLFW compile options http://www.glfw.org/docs/latest/compile.html#compile_options_osx

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# Add custom cmake modules
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

# add_definitions(-Wall -std=c++0x)
add_definitions(-Wall)

# Include the dependencies, tests and source
add_subdirectory(lib)
add_subdirectory(src)
