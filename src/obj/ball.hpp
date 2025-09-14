#pragma once

class Padel;
#include "raylib-wrapper.hpp"
struct Ball {
    Screen screen;
    Vector2 Pos;
    Color color = WHITE;
    Vector2 Speed{5.0f, 4.0f};
    static constexpr int radius{30};


    void move(Padel& padel, Padel& padel2);
    bool NotOutOfBounds() const;
    bool TopOrBottom();
    bool hitSides();
    bool Sides();
    void Draw();


    Ball() {
        Pos.x = float(GetScreenWidth()) / 2;
        Pos.y = float(GetScreenHeight()) / 2;
        Speed.x = 10;
        Speed.y = 10;
    }
};
