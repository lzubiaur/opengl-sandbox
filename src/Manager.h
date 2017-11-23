#ifndef ENGINE_MANAGER_H
#define ENGINE_MANAGER_H

#include "Node.h"
#include "Window.h"
#include "Renderer.h"

namespace Engine {

  class Manager {
  public:
    Manager();
    ~Manager();
    void mainLoop();
  private:
    Renderer *renderer;
    Window *window;
    Node *main_node;
  };

}

#endif // ENGINE_MANAGER_H
