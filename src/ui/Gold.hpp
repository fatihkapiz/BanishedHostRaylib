#pragma once
#include "../GameData.hpp"
#include "../constants/Constants.hpp"
#include "UIElement.hpp"
#include "raylib.h"

class Gold : public UIElement {
public:
  Rectangle rect;
  Texture2D texture;
  std::string text;
  GameData &gamedata;

  Gold(float x, float y, float width, float height, GameData &gamedata)
      : UIElement("Gold"), text(std::string("0")), gamedata(gamedata) {
    rect = {x, y, width, height};
    text = std::to_string(gamedata.getGold());
  }
  void update() override { text = std::to_string(gamedata.getGold()); }
  void render() override {
    DrawRectangleRec(rect, RED);
    DrawText(text.c_str(),
             rect.x + rect.width / 2 -
                 MeasureText(text.c_str(), Constants::fontsize) / 2,
             rect.y + rect.height / 2 - Constants::fontsize / 2,
             Constants::fontsize, WHITE);
    DrawRectangleLinesEx(rect, 5, BLACK);
  }
};
