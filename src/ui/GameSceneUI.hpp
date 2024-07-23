#pragma once
#include "ClickableUIElement.hpp"
#include "Gold.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class UI {
private:
  std::vector<std::unique_ptr<UIElement>> elements;

  std::unique_ptr<UIElement> gold = std::make_unique<Gold>();

public:
  void handleInput() {
    for (auto &el : elements) {
      if (auto clickableElement =
              dynamic_cast<ClickableUIElement *>(el.get())) {
        clickableElement->handleInput();
      }
    }
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
