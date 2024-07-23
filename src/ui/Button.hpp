#include "ClickableUIElement.hpp"
#include "IClickable.hpp"
#include "UI.hpp"
#include "raylib.h"

class Button : public ClickableUIElement {
private:
  Rectangle rect;
  Color color;
  std::string text;
  std::function<void()> onClickHandler;

public:
  int fontSize;

  Button(const std::string name, float x, float y, float width, float height,
         const std::string &text, int fontSize,
         std::function<void()> onClickHandler)
      : ClickableUIElement(name), rect{x, y, width, height}, text{text},
        onClickHandler(onClickHandler), fontSize{fontSize} {
    color = RED;
  }

  void onClick() override { onClickHandler(); }

  void update() override {}

  void handleInput() override {
    if (CheckCollisionPointRec(GetMousePosition(), rect) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      onClick();
    }
  }

  void render() override {
    DrawRectangleRec(rect, color);
    DrawText(text.c_str(),
             rect.x + rect.width / 2 - MeasureText(text.c_str(), fontSize) / 2 +
                 10,
             rect.y + rect.height / 2 - fontSize / 2, fontSize, WHITE);
  }
};
