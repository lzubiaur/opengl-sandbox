#ifndef ENGINE_NODE_H
#define ENGINE_NODE_H

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>

namespace Engine {

  class Node {
  public:
    Node();
    virtual ~Node();
    virtual bool init();
    void addChild(Node *child);
    void draw();
    void update(float dt);
  protected:
    std::vector<Node *> _children;
    GLuint _vao,_vbo;
    std::vector<float> _vertices;
  };
  using NodeUniquePrt = std::unique_ptr<Node>;

} /* Engine */

#endif // ENGINE_NODE_H
