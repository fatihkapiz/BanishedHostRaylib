#pragma once
#include "../ui/GameSceneUI.hpp"
#include "Scene.hpp"
#include "raylib.h"
#include <iostream>
#include <memory>

class GameScene : public Scene {
private:
  std::unique_ptr<GameSceneUI> ui;
  GameData &gamedata;

  void InitializeUI() {}

public:
  GameScene(GameData &gamedata) : gamedata(gamedata) {
    ui = std::make_unique<GameSceneUI>(gamedata);
  }
  ~GameScene() {}

  bool handleInput() override {
    if (ui->handleInput()) {
      return true;
    }

    // handle game input here

    return false;
  }

  void update() override { ui->update(); }

  void render() override { ui->render(); }

  void RosterButton() {}
};
