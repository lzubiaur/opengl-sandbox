#include "Manager.h"

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <utility>
#include <memory>
#include "shader_sources.h"
#include "common.h"

namespace Engine {

  Manager::Manager()
  {
    spdlog::stdout_color_mt("console");
    spdlog::set_level(spdlog::level::debug);

    window = std::make_unique<Window>(640,480);
    window->init();

    rootNode = std::make_unique<Node>();

    auto vertexShader = std::make_unique<Shader>(_default_vertex_source, ShaderType::VertexShader);
    vertexShader->compile();
    auto fragShader = std::make_unique<Shader>(_default_fragment_source, ShaderType::FragmentShader);
    fragShader->compile();

    auto program = std::make_unique<Program>(*vertexShader, *fragShader);

    Shader::cache.insert(std::make_pair("defaultVertex",std::move(vertexShader)));
    Shader::cache.insert(std::make_pair("defaultFrag", std::move(fragShader)));
    Program::cache.insert(std::make_pair("defaultProgram", std::move(program)));
    // Shader::cache.insert({"hello",std::move(vertexShader)}); // doesn't compile. Ask on stack overflow.
  }

  Manager::~Manager()
  {
    LOG_DEBUG("Manager destructor");
  }

  void Manager::mainLoop() {
    while (!glfwWindowShouldClose(window->window)) {
      glfwPollEvents();
      glClear(GL_COLOR_BUFFER_BIT);
      rootNode->update(0);
      rootNode->draw();
      glfwSwapBuffers(window->window);
    }
    glfwTerminate();
  }

}
