#pragma once
#include "../Gamedata.hpp"
#include "../constants/Constants.hpp"
#include "Gold.hpp"
#include "Panel.hpp"
#include "raylib.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class GameSceneUI : public Panel {
private:
  std::vector<std::shared_ptr<UIElement>> elements;
  GameData &gamedata;

public:
  GameSceneUI(GameData &gamedata) : Panel("GameSceneUI"), gamedata(gamedata) {
    std::shared_ptr<Panel> top = std::make_shared<Panel>("Top");
    std::cout << "Top panel created" << std::endl;
    elements.push_back(top);
    std::cout << "top panel pushed" << std::endl;
    top->AddElement(std::make_shared<Gold>(0, 0, 100, 50, gamedata));
    std::cout << "gold pushed" << std::endl;
    top->setPanelVisible();
  }

  bool handleInputImpl() {
    std::cout << "UI handle input called" << std::endl;
    return true;
  }
  // Update all UI elements
  void update() {
    for (auto &el : elements) {
      el->update();
    }
  }

  void render() {
    for (auto &el : elements) {
      el->render();
    }
  }
};
