#include "Node.h"

namespace Engine {

  Node::Node()
  {}

  Node::~Node()
  {}

  void Node::addChild(Node *child) {
    children.push_back(child);
  }

  void Node::draw() {
    for (Node *child : children) {
      child->draw();
    }
  }

  void Node::update(float dt) {

  }

} /* Engine */
