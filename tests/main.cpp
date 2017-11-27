// #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Window.h"
#include <iostream>
#include "spdlog/spdlog.h"

int main(int argc, char *argv[]) {
  spdlog::stdout_color_mt("console");
  spdlog::set_level(spdlog::level::debug);

  Engine::Window window(640,480);
  if (!window.init()) {
    return EXIT_FAILURE;
  }

  int rc = Catch::Session().run(argc, argv);

  return rc;
}
