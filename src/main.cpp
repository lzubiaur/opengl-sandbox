/* Copyright (c) 2017 Laurent Zubiaur
 * MIT License (http://opensource.org/licenses/MIT)
 */

#include "Manager.h"

// #include <imgui.h>
// #include <imgui_impl_glfw_gl3.h>

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

#ifdef _WIN32
int CALLBACK WinMain(
  HINSTANCE hInstance,     /* handle to the current instance of the application. */
  HINSTANCE hPrevInstance, /* handle to the previous instance of the application */
  LPSTR     lpCmdLine,     /* command line for the application */
  int       nCmdShow) {    /* controls how the window is to be shown */
#else
/* Linux and OSX use standard entry point */
int main(int argc, char *argv[]) {
#endif

  Engine::Manager manager;
  manager.mainLoop();

  // ImGui_ImplGlfwGL3_Init(window,false);
  // glClearColor(0.1, 0.28, 0.35, 1);
  //
  // bool show_test_window = true;
  // ImGui_ImplGlfwGL3_NewFrame();
  // ImGui::ShowTestWindow(&show_test_window);
  // ImGui::Render();
  //
  // ImGui_ImplGlfwGL3_Shutdown();

  exit(EXIT_SUCCESS);
}
