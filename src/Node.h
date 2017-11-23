#ifndef ENGINE_NODE_H
#define ENGINE_NODE_H

#include <vector>

namespace Engine {

  class Node {
  public:
    Node();
    virtual ~Node();
    void addChild(Node *child);
    void draw();
    void update(float dt);
  protected:
    std::vector<Node *> children;
  };

} /* Engine */

#endif // ENGINE_NODE_H
