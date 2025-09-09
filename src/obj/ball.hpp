#pragma once

class Padel;
#include "raylib-wrapper.hpp"
struct Ball {
    Screen screen;
    Vector2 Pos;
    Color color = WHITE;
    Vector2 Speed{10.0f, 10.0f};
    static constexpr int radius{50};


    void move(Padel& padel);
    bool NotOutOfBounds();
    bool TopOrBottom();
    void Draw();


    Ball() {
        Pos.x = float(GetScreenWidth()) / 2;
        Pos.y = float(GetScreenHeight()) / 2;
        Speed.x = 10;
        Speed.y = 10;
    }
};
