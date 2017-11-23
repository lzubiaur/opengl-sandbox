#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include <iostream>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

namespace Engine {

  enum ShaderType { VertexShader, FragmentShader };

  class Shader {
  public:
    Shader(std::string const& source, ShaderType type);
    ~Shader();
    bool compile();
  protected:
    std::string shader_source;
    GLuint shader_handler;
  };

  class Renderer {
  public:
    void render();
  };

}

#endif
