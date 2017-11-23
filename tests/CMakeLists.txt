cmake_minimum_required(VERSION 3.3)

project(tests C CXX)

include_directories(
  ${CATCH_HEADERS}
)

# C++11 is required
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")

# Runtime executable
add_executable(tests main.cpp)
# Linking against static libraries
# target_link_libraries(tests ...)
set_target_properties(tests PROPERTIES OUTPUT_NAME "run-tests")
