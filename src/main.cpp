#include "obj/ball.hpp"
#include "obj/padel.hpp"
#include "obj/raylib-wrapper.hpp"
int main() {
    Screen screen;
    Padel Player;
    Padel Enemy;
    Ball ball;
    Enemy.Pos.x = GetScreenWidth() + 10;

    while (!WindowShouldClose()) {
        Player.move();
        Enemy.move();
        ball.move(Player);

        BeginDrawing();
        Player.draw();
        Enemy.draw();
        ball.Draw();

        ClearBackground(screen.bgColor);
        EndDrawing();
    }
}
