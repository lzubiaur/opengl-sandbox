#include "Renderer.h"

namespace Engine {

  Shader::Shader(std::string const& source, ShaderType type) : shader_source(source) {
    shader_handler = glCreateShader(type == ShaderType::VertexShader ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
  }

  Shader::~Shader() {
    glDeleteShader(shader_handler);
  }

  bool Shader::compile() {
    const GLchar *str = shader_source.c_str();
    glShaderSource(shader_handler, 1 ,&str, nullptr);
    glCompileShader(shader_handler);
    GLint status;
    char log[512];
    glGetShaderiv(shader_handler, GL_COMPILE_STATUS, &status);
    if (!status) {
      glGetProgramInfoLog(shader_handler, 512, nullptr, log);
    }
    return status == 1;
  }

  void Renderer::render() {

  }

}
