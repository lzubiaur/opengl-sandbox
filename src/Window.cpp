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
    window = glfwCreateWindow(width, height, "Hello", NULL, NULL);
    if (!window) {
      glfwTerminate();
      return false;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (gl3wInit()) {
      LOG_ERROR("Failed to initialize OpenGL");
      return false;
    }
    if (!gl3wIsSupported(ENGINE_GL_MAJOR, ENGINE_GL_MINOR)) {
      LOG_ERROR("OpenGL {}.{} not supported", ENGINE_GL_MAJOR, ENGINE_GL_MINOR);
      return false;
    }

    glfwSwapInterval(1); // Enable vsync

    LOG_DEBUG("OpenGL {}, GLSL {}", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

    return true;
  }

}
