#include "Manager.h"

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw_gl3.h>

#include <iostream>
#include <utility>
#include <memory>
#include "shader_sources.h"
#include "common.h"

namespace Engine {

  Manager::Manager()
  {
    window = std::make_unique<Window>(640,480);
    if (!window->init()) {
      return;
    }

    rootNode = std::make_unique<Node>();
    if (!rootNode->init()) {
      return;
    }

    auto vertexShader = std::make_unique<Shader>(_default_vertex_source, ShaderType::VertexShader);
    auto fragShader = std::make_unique<Shader>(_default_fragment_source, ShaderType::FragmentShader);
    if (!vertexShader->compile() && !fragShader->compile()) {
      return;
    }

    auto program = std::make_unique<Program>();
    if (!program->link(*vertexShader, *fragShader)) {
      return;
    }

    Shader::cache.insert(std::make_pair("defaultVertex",std::move(vertexShader)));
    Shader::cache.insert(std::make_pair("defaultFrag", std::move(fragShader)));
    Program::cache.insert(std::make_pair("defaultProgram", std::move(program)));

    ImGui_ImplGlfwGL3_Init(window->window,false);
  }

  Manager::~Manager()
  {
    LOG_DEBUG("Manager destructor");
  }

  void Manager::mainLoop() {
    glClearColor(.1f,.2f,.1f,1);
    glViewport(0,0,640,480);
    while (!glfwWindowShouldClose(window->window)) {
      glClear(GL_COLOR_BUFFER_BIT);
      rootNode->update(0);
      rootNode->draw();
      glfwSwapBuffers(window->window);
      glfwPollEvents();
    }
    glfwTerminate();
  }

}
