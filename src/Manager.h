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
    // Renderer *renderer;
    WindowUniquePtr window;
    NodeUniquePrt rootNode;
  };

}

#endif // ENGINE_MANAGER_H
