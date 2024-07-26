#pragma once
#include "../ui/GameSceneUI.hpp"
#include "Scene.hpp"
#include "raylib.h"
#include <iostream>
#include <memory>

class GameScene : public Scene {
private:
  std::unique_ptr<GameSceneUI> ui;
  void InitializeUI() {}

public:
  GameScene() { ui = std::make_unique<GameSceneUI>(); }
  ~GameScene() {}

  bool handleInput() override {
    if (ui->handleInput()) {
      return true;
    }

    // handle game input here

    return false;
  }

  void update() override { ui->update(); }

  void render() override {
    ui->render();
    DrawText("Game Scene active", 10, 10, 20, BLACK);
  }

  void RosterButton() {}
};
