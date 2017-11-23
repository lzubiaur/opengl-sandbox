/* Copyright (c) 2017 Laurent Zubiaur
 * MIT License (http://opensource.org/licenses/MIT)
 */

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw_gl3.h>

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
/* Faster builds with smaller header files */
#define VC_EXTRALEAN 1
#define WIN32_LEAN_AND_MEAN 1
/* TODO investigte the "NOapi" symbols */
/* (https://msdn.microsoft.com/en-us/library/windows/desktop/aa383745(v=vs.85).aspx) */
#include <windows.h> /* WindMain */
#endif

static void error_callback(int error, const char* description) {
  fputs(description, stderr);
}

#ifdef _WIN32
int CALLBACK WinMain(
  HINSTANCE hInstance,     /* handle to the current instance of the application. */
  HINSTANCE hPrevInstance, /* handle to the previous instance of the application */
  LPSTR     lpCmdLine,     /* command line for the application */
  int       nCmdShow) {    /* controls how the window is to be shown */
  /* Get command line count and string from global variable __argc and __argv */
  return cpr_start(__argc, __argv);
}
#else
/* Linux and OSX use standard entry point */
int main(int argc, char *argv[]) {
  GLFWwindow* window;

  glfwSetErrorCallback(error_callback);

  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }

  // At least OpenGL 3.2 is required by GL3W and ImGui
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
#endif

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  if (gl3wInit()) {
    fprintf(stderr, "failed to initialize OpenGL\n");
    return -1;
  }
  if (!gl3wIsSupported(3, 2)) {
    fprintf(stderr, "OpenGL 3.2 not supported\n");
    return -1;
  }
  printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

  ImGui_ImplGlfwGL3_Init(window,false);
  glClearColor(0.1, 0.28, 0.35, 1);

  bool show_test_window = true;

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    ImGui_ImplGlfwGL3_NewFrame();
    ImGui::ShowTestWindow(&show_test_window);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    glfwSwapBuffers(window);
  }

  ImGui_ImplGlfwGL3_Shutdown();
  glfwTerminate();

  exit(EXIT_SUCCESS);
}

#endif
