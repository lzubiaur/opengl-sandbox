#include "Manager.h"

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

namespace Engine {

  Manager::Manager()
  {
    window = new Window(640,480);
    window->init();
    main_node = new Node();
    // renderer = new Renderer();
  }

  Manager::~Manager() {
    delete window;
    delete main_node;
  }

  void Manager::mainLoop() {
    while (!glfwWindowShouldClose(window->window)) {
      glfwPollEvents();
      glClear(GL_COLOR_BUFFER_BIT);
      main_node->update(0);
      main_node->draw();
      glfwSwapBuffers(window->window);
    }
    glfwTerminate();
  }

}
