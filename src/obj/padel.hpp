#pragma once
#include "raylib-wrapper.hpp"
#include <raylib.h>
#include <string>

enum class Side { RIGHT, LEFT };
struct Padel {
    Screen screen;
    static constexpr int HEIGHT = 200;
    static constexpr int WIDTH = 20;
    int health = 3;
    int score = 0;
    std::string scorestr = std::to_string(score);
    Vector2 Pos;
    Color color = RAYWHITE;
    float center = Pos.y + HEIGHT / 2.0f;
    Rectangle object;

    void move() {
        if (IsKeyDown(KEY_DOWN)) {
            object.y += 10;
        } else if (IsKeyDown(KEY_UP)) {
            object.y -= 10;
        }
    }
    void draw() { DrawRectangleRec(object, WHITE); }
    Padel(Side side) {
        if (side == Side::LEFT) {
            Pos = {10.0f, GetScreenHeight() / 2.0f - HEIGHT / 2.0f};
        } else if (side == Side::RIGHT) {
            Pos = {float(GetScreenWidth() - WIDTH - 10), GetScreenHeight() / 2.0f - HEIGHT / 2.0f};
        }
        this->object = {Pos.x, Pos.y, WIDTH, HEIGHT};
    }
};
