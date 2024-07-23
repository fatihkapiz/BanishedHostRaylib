#pragma once
#include "ClickableUIElement.hpp"
#include "Gold.hpp"
#include <iostream>
#include <string>
#include <vector>

class UiVectorParent {
private:
  std::vector<std::unique_ptr<UIElement>> elements;

public:
  UiVectorParent() {}

  template <typename T, typename... Args,
            typename = std::enable_if_t<std::is_base_of_v<UIElement, T>>>
  void addElement(Args &&...args) {
    elements.push_back(std::make_unique<T>(std::forward<Args>(args)...));
  }

  void removeElement(const std::string &name) {
    for (auto it = elements.begin(); it != elements.end();) {
      if ((*it)->name == name) {
        it = elements.erase(it);
      } else {
        it++;
      }
    }
  }

  UIElement *getElement(const std::string &name) {
    for (auto it = elements.begin(); it != elements.end(); ++it) {
      if ((*it)->name == name)
        return it->get();
    }
    return nullptr;
  }

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
