cmake_minimum_required(VERSION 3.3)

include_directories(
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_BINARY_DIR}/src
  ${GLFW_HEADERS}
)

# Custom C flags
# set(C_FLAGS -std=c99 -pedantic-errors -pedantic)
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")

add_library(engine STATIC Renderer.cpp Window.cpp Manager.cpp Node.cpp)
target_link_libraries(engine gl3w glfw imgui ${GLFW_LIBRARIES})
target_include_directories(engine PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Runtime executable
add_executable(rt main.cpp)
# Linking against static GLFW libary. GLFW_LIBRARIES must be used to add
# dependencies (http://www.glfw.org/docs/latest/build.html).
target_link_libraries(rt engine gl3w glfw imgui ${GLFW_LIBRARIES})
set_target_properties(rt PROPERTIES OUTPUT_NAME ${RUNTIME_NAME})
