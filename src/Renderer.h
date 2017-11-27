#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <unordered_map>
#include <memory>

namespace Engine {

  enum ShaderType { VertexShader, FragmentShader };

  class Program;
  class Shader;

  // using ProgramUniquePtr = std::unique_ptr<Program>;
  // using ShaderUniquePtr = std::unique_ptr<Shader>;

  using ShaderCache = std::unordered_map<std::string, std::shared_ptr<Shader>>;
  using ProgramCache = std::unordered_map<std::string, std::shared_ptr<Program>>;

  class Shader {
  public:
    Shader(char const* source, ShaderType type);
    Shader(std::string const& source, ShaderType type);
    ~Shader();
    bool compile();
    static ShaderCache cache;
    friend Program;
  protected:
    std::string shader_source;
    GLuint _gl_shader_handler;
  };

  class Program {
  public:
    Program();
    ~Program();
    bool link(Shader const& vertex, Shader const& frag);
    void use() const { glUseProgram(_gl_program_handler); }
    static ProgramCache cache;
  protected:
    GLuint _gl_program_handler;
  };

  class Renderer {
  public:
    void render();
  };

}

#endif
