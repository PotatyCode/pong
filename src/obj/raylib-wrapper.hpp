#ifndef RAYLIB_WRAPPER_HPP
#define RAYLIB_WRAPPER_HPP

#include "raylib.h"
class Screen {
  private:
    static constexpr int screenHeight = 1000;
    static constexpr int screenWidth = screenHeight * 1.6;
    static constexpr int FPS = 60;
    const char* title = "Pong";

  public:
    Screen() {
        InitWindow(screenWidth, screenHeight, title);
        SetTargetFPS(60);
    }
    static constexpr Color bgColor = BLACK;
};
#endif
