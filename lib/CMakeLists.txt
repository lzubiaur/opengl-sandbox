cmake_minimum_required(VERSION 3.3)
project(lib)

# Add third-party libraries
add_subdirectory(gl3w)
add_subdirectory(glfw)
add_subdirectory(imgui)

set(SPDLOG_HEADERS "${PROJECT_SOURCE_DIR}/spdlog/include" PARENT_SCOPE)
set(GLFW_HEADERS "${PROJECT_SOURCE_DIR}/glfw/include" PARENT_SCOPE)
set(CATCH_HEADERS "${PROJECT_SOURCE_DIR}/catch" PARENT_SCOPE)
