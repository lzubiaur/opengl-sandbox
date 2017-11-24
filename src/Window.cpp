#include "Window.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "common.h"

namespace Engine {

  static void error_callback(int error, const char* description) {
    std::cerr << "ERROR: " << description << " [" << error << "]" << std::endl;
  }

  Window::Window(int width, int height) : width(width), height(height)
  {}

  bool Window::init() {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
      return false;
    }

    // At least OpenGL 3.2 is required by GL3W and ImGui
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ENGINE_GL_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, ENGINE_GL_MINOR);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
#endif

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
      glfwTerminate();
      return false;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (gl3wInit()) {
      fprintf(stderr, "failed to initialize OpenGL\n");
      return false;
    }
    if (!gl3wIsSupported(ENGINE_GL_MAJOR, ENGINE_GL_MINOR)) {
      fprintf(stderr, "OpenGL 3.2 not supported\n");
      return false;
    }

    glfwSwapInterval(1); // Enable vsync

    printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

    return true;
  }

}
