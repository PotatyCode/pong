#ifndef RAYLIB_WRAPPER_HPP
#define RAYLIB_WRAPPER_HPP

#include "raylib.h"
#include <functional>
class Screen {
  private:
    static constexpr int screenHeight = 1000.0f;
    static constexpr int screenWidth = screenHeight * 1.6f;
    static constexpr int FPS = 60;
    const char* title = "Pong";

  public:
    Screen() {
        InitWindow(screenWidth, screenHeight, title);
        SetTargetFPS(60);
    }
    static constexpr Color bgColor = BLACK;
    Vector2 center = {screenWidth / 2.0f, screenHeight / 2.0f};
};
#endif
