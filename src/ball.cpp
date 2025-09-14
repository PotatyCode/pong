#include "obj/ball.hpp"
#include "obj/padel.hpp"
#include <cstdlib>
#include <raylib.h>
#include <string>
void Ball::move(Padel& Player, Padel& Enemy) {
    Pos.x += Speed.x;
    Pos.y += Speed.y;
    if (Pos.y - radius <= 0 || Pos.y + radius >= GetScreenHeight()) {
        Speed.y *= -1;

    } else if (CheckCollisionCircleRec(Pos, radius, Player.object)) {
        Speed.x = std::abs(Speed.x);
        Player.score++;
        Player.scorestr = std::to_string(Player.score);
        Pos.x = Player.object.x + Player.object.width + radius + 1;

    } else if (CheckCollisionCircleRec(Pos, radius, Enemy.object)) {
        Speed.x = -std::abs(Speed.x);
        Enemy.score++;
        Enemy.scorestr = std::to_string(Enemy.score);
    }
}
bool Ball::NotOutOfBounds() const {
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
bool Ball::hitSides() {
    if (Pos.x - radius <= 0 || Pos.x + radius >= GetScreenWidth()) {
        return true;
    } else {
        return false;
    }
}
void Ball::Draw() {
    DrawCircleV(Pos, radius, color);
};
