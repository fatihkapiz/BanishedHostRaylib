#pragma once
#include "../GameData.hpp"
#include "UIElement.hpp"
#include "raylib.h"

class GoldBackup : public UIElement {
private:
  Rectangle rect;
  Color color;

public:
  Gold(std::string name, float x, float y, float width, float height, Color col)
      : UIElement(name) {
    rect = {x, y, width, height};
  }

  void update() override {}

  void render() override {
    DrawRectangleRec(rect, color);
    DrawText(GameData.gold.c_str(),
             rect.x + rect.width / 2 - MeasureText(text.c_str(), fontSize) / 2 +
                 10,
             rect.y + rect.height / 2 - fontSize / 2, fontSize, WHITE);
  }
};
