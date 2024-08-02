#pragma once
#include "../Hexmap.hpp"
#include "../ui/GameSceneUI.hpp"
#include "Scene.hpp"
#include <memory>

class CombatScene : public Scene {
private:
  std::unique_ptr<GameSceneUI> ui;
  std::unique_ptr<Hexmap> hexmap;
  GameData &gamedata;
  Camera2D camera;

public:
  CombatScene(GameData &gamedata) : gamedata(gamedata) {
    ui = std::make_unique<GameSceneUI>(gamedata);
    hexmap = std::make_unique<Hexmap>(12, 12, 40);

    // camera
    camera.target = (Vector2){0, 0}; // Initial target
    // camera.offset =
    // (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
  }
  ~CombatScene() {}

  bool handleInput() override {
    if (ui->handleInput()) {
      return true;
    }

    // handle game input here
    return false;
  }

  void update() override { ui->update(); }

  void render() override {
    BeginMode2D(camera); // Apply camera transformations
    //
    hexmap->render();
    ui->render();

    EndMode2D(); // End camera transformations
  }

  void RosterButton() {}
};
