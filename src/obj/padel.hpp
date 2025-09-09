#pragma once
#include "raylib-wrapper.hpp"

struct Padel {
    Screen screen;
    static constexpr int HEIGHT = 200;
    static constexpr int WIDTH = 10;
    int score = 0;
    Vector2 Pos = {0, GetScreenHeight() / 2.0f};
    Color color = RAYWHITE;
    Rectangle object{Pos.x, Pos.y, WIDTH, HEIGHT};

    void move() {
        if (IsKeyDown(KEY_DOWN)) {
            Pos.x += 10;
        } else if (IsKeyDown(KEY_UP)) {
            Pos.y -= 10;
        }
    }
    void draw() { DrawRectangleRec(object, WHITE); }
};
