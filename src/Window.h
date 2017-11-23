#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

namespace Engine {

  class Manager;

  class Window {
  public:
    Window(int width, int height);
    bool init();
    friend Manager;
  protected:
    GLFWwindow *window;
    int width, height;
  };

}

#endif
