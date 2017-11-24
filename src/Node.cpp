#include "Node.h"
#include <iostream>
#include "Renderer.h"
#include "common.h"

namespace Engine {

  Node::Node()
  {}

  Node::~Node()
  {
    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
  }

  bool Node::init() {
    _vertices = {
      -0.5f, -0.5f, 0.0f,
      0.5f, -0.5f, 0.0f,
      0.0f,  0.5f, 0.0f
    };

    glGenBuffers(1, &_vbo);
    glGenVertexArrays(1, &_vao);

    return true;
  }

  void Node::addChild(Node *child) {
    _children.push_back(child);
  }

  void Node::draw() {
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*_vertices.size(), &_vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    Program::cache["defaultProgram"]->use();
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // for (Node *child : _children) {
    //   child->draw();
    // }
  }

  void Node::update(float dt) {

  }

} /* Engine */
