#pragma once
#include "Scene.hpp"
#include "raylib.h"

class MenuScene : public Scene {
private:
public:
  MenuScene() {}
  ~MenuScene() {}
  void update() override {
    if (IsKeyPressed(KEY_ENTER)) {
      screen = PLAY;
    }
  }
  void render() override {
    DrawRectangle(200, 300, 200, 100, GREEN);
    DrawText("PLAY", 200, 300, 20, RED);
  }
};