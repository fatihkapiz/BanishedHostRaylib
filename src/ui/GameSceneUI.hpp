#pragma once
#include "Panel.hpp"
#include "raylib.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Gold : public UIElement {
public:
  Rectangle rect;
  Texture2D texture;
  std::string text;

  Gold(float x, float y, float width, float height)
      : UIElement("Gold"), text(std::string("0")) {
    rect = {x, y, width, height};
  }
  void update() override {}
  void render() override { DrawRectangleRec(rect, RED); }
};

class GameSceneUI : public Panel {
private:
  std::vector<std::shared_ptr<UIElement>> elements;

public:
  GameSceneUI() : Panel("GameSceneUI") {
    std::shared_ptr<Panel> top = std::make_shared<Panel>("Top");
    std::cout << "Top panel created" << std::endl;
    elements.push_back(top);
    std::cout << "top panel pushed" << std::endl;
    top->AddElement(std::make_shared<Gold>(0, 0, 200, 50));
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
