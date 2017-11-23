#include "catch.hpp"
#include "Renderer.h"
#include <iostream>

TEST_CASE("Compile shader success", "[RENDERING]") {
  const char *vertex_source =
    "#version 330 core\n" \
    "layout (location = 0) in vec3 aPos;\n" \
    "void main() { \n" \
    "  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" \
    "}\n\0";

  Engine::Shader vertex(std::string(vertex_source), Engine::ShaderType::VertexShader);
  REQUIRE(vertex.compile());

  const char *fragment_source =
    "#version 330 core\n" \
    "out vec4 FragColor;\n" \
    "void main() {\n" \
    "  FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n" \
    "}\n\0";

  Engine::Shader frag(std::string(fragment_source), Engine::ShaderType::FragmentShader);
  frag.compile();
}

TEST_CASE("Compile shader failure", "[RENDERING]") {
  const char *source = "";
  Engine::Shader shader(std::string(source), Engine::ShaderType::VertexShader);
  REQUIRE(shader.compile() == false);
}
