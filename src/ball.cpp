#include "obj/ball.hpp"
#include "obj/padel.hpp"
#include <raylib.h>
void Ball::move(Padel& padel) {
    Pos.x += Speed.x;
    Pos.y += Speed.y;
    if (Pos.y - radius <= 0 || Pos.y + radius >= GetScreenHeight()) {
        Speed.x *= -1;
        Speed.y *= -1;
    } else if (CheckCollisionCircleRec(Pos, radius, padel.object)) {
        Speed.x *= -1;
        Speed.y *= -1;
        padel.score++;
    }
}
bool Ball::NotOutOfBounds() {
    bool outOfBounds = true;
    if (Pos.x + 50 > GetScreenWidth() || Pos.x - 50 > 0) {
        outOfBounds = false;
    }
    if (Pos.y + 50 > GetScreenHeight() || Pos.y - 50 > 0) {
        outOfBounds = false;
    }
    return outOfBounds;
}
bool Ball::TopOrBottom() {
    bool TopOrBottom{false};
    if (radius + Pos.y >= GetScreenHeight() || Pos.y - radius <= 0) {
        TopOrBottom = true;
    }
    return TopOrBottom;
}
void Ball::Draw() {
    DrawCircleV(Pos, radius, color);
};
