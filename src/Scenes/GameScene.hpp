#pragma once
#include "../ui/Button.hpp"
#include "../ui/UI.hpp"
#include "../ui/UiVectorParent.hpp"
#include "Scene.hpp"
#include "raylib.h"
#include <iostream>

class GameScene : public Scene {
private:
  UiVectorParent ui;

public:
  GameScene() {
    ui = UiVectorParent{};
    ui.addElement<Button>(
        std::string("NextTurnButton"), 0, 0, 100, 100, "Next Turn", 20,
        []() { std::cout << "Next turn button clicked" << std::endl; });
  }
  ~GameScene() {}

  void update() override {
    ui.update();
    ui.handleInput();
  }

  void render() override { ui.render(); }

  void RosterButton() {}
};
