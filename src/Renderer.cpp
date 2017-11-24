#include "Renderer.h"

namespace Engine {

  ShaderCache Shader::cache = ShaderCache();

  Shader::Shader(char const* source, ShaderType type) : Shader(std::string(source), type)
  {}

  Shader::Shader(std::string const& source, ShaderType type) : shader_source(source) {
    _gl_shader_handler = glCreateShader(type == ShaderType::VertexShader ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
  }

  Shader::~Shader() {
    glDeleteShader(_gl_shader_handler);
  }

  bool Shader::compile() {
    const GLchar *str = shader_source.c_str();
    glShaderSource(_gl_shader_handler, 1 ,&str, nullptr);
    glCompileShader(_gl_shader_handler);
    GLint status;
    glGetShaderiv(_gl_shader_handler, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE) {
      GLchar buf[1024];
      GLsizei len;
      glGetShaderInfoLog(_gl_shader_handler, 1024, &len, buf);
      std::cerr << "ERROR: Shader compilation failed: " << std::string(buf,len) << std::endl;
    }
    return status == GL_TRUE;
  }

  //////////////////////////// Engine::Program /////////////////////////////////

  ProgramCache Program::cache = ProgramCache();

  Program::Program(Shader const& vertex, Shader const& frag)
  {
    _gl_program_handler = glCreateProgram();
    glAttachShader(_gl_program_handler, vertex._gl_shader_handler);
    glAttachShader(_gl_program_handler, frag._gl_shader_handler);
    glLinkProgram(_gl_program_handler);
    GLint status;
    char log[512];
    glGetShaderiv(_gl_program_handler, GL_LINK_STATUS, &status);
    if (!status) {
      glGetProgramInfoLog(_gl_program_handler, 512, nullptr, log);
      std::cerr << "ERROR: " << log << std::endl;
    }
  }

  Program::~Program()
  {}
    
  /////////////////////////////// Engine::Renderer /////////////////////////////

  void Renderer::render() {

  }

}
