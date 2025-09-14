#include "obj/ball.hpp"
#include "obj/button.hpp"
#include "obj/padel.hpp"
#include <raylib.h>
#include <vector>
class Game {
  public:
    enum GameStates {
        PLAYING,
        PAUSED,
        GAMEOVER,
    };

    GameStates currentState = PLAYING;
    Screen screen;
    Padel Player;
    Padel Enemy;
    Ball ball;
    std::vector<button> Buttons;

    Game() : screen(), Player(Side::LEFT), Enemy(Side::RIGHT), ball() {
        button btnExit(200, GetScreenHeight() / 3.0f + 200.0f, 200, 100, "Exit");
        btnExit.SetOnPressed([&]() { CloseWindow(); });
        Buttons.push_back(btnExit);

        button btnRestart(GetScreenWidth() / 2.0f, GetScreenHeight() / 3.0f + 200.0f, 400, 100, "Restart");
        btnRestart.SetOnPressed([&]() {
            Player.score = 0;
            Enemy.score = 0;
            ball.Pos = screen.center;
            currentState = PLAYING;
        });
        Buttons.push_back(btnRestart);
    }
};

void DrawSplashScreen(std::vector<button>& button);
void UpdateGame(Game& game);
void DrawGame(Game& game);
int main() {
    Game game;
    while (!WindowShouldClose()) {
        UpdateGame(game);
        DrawGame(game);
    }
}
void DrawSplashScreen(std::vector<button>& Buttons) {
    DrawText("Game Over", 0, GetScreenHeight() / 3, 200, WHITE);
    for (int i = 0; i < Buttons.size(); i++) {
        Buttons[i].draw();
    }
}
void UpdateGame(Game& game) {
    switch (game.currentState) {
        case Game::PLAYING: {
            game.Player.move();
            game.Enemy.move();
            game.ball.move(game.Player, game.Enemy);

            if (game.ball.hitSides()) {
                game.currentState = game.GAMEOVER;
            }
            if (IsKeyPressed(KEY_SPACE)) {
                game.currentState = game.PAUSED;
            }
            break;
        }
        case Game::PAUSED: {
            for (int i = 0; i < game.Buttons.size(); i++) {
                game.Buttons[i].update();
            }

            break;
        }
        case Game::GAMEOVER: {
            for (int i = 0; i < game.Buttons.size(); i++) {
                game.Buttons[i].update();
            }
            break;
        }
    }
}
void DrawGame(Game& game) {
    BeginDrawing();
    ClearBackground(game.screen.bgColor);
    switch (game.currentState) {
        case Game::PLAYING: {
            game.Player.draw();
            game.Enemy.draw();
            game.ball.Draw();
            break;
        }
        case Game::PAUSED: {
            DrawSplashScreen(game.Buttons);
            break;
        }
        case Game::GAMEOVER: {
            DrawSplashScreen(game.Buttons);
            break;
        }
    }
    EndDrawing();
}
void DrawScores(Padel& padel, Screen& screen) {
    DrawText(padel.score, screen.center., int posY, int fontSize, Color color)
}
