#include "raylib-wrapper.hpp"
#include <functional>
struct button {
    Rectangle rec;
    const char* Text;

    bool ButtonPressed() {
        if (CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            return true;
        } else {
            return false;
        }
    }
    void DrawTextInButton() { DrawText(Text, rec.x, rec.y, 100, BLACK); }
    void draw() {
        DrawRectangle(rec.x, rec.y, rec.width, rec.height, WHITE);
        DrawTextInButton();
    }

    std::function<void()> OnPressed;
    void SetOnPressed(std::function<void()> action) { OnPressed = action; }
    void update() {
        if ((ButtonPressed())) {
            OnPressed();
        }
    }
    button(const float Xpos, const float Ypos, const float length, const float width, const char* Text) {
        rec = {Xpos, Ypos, length, width};
        this->Text = Text;
    }
};
