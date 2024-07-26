#pragma once
#include "UIElement.hpp"
#include <algorithm>
#include <memory>
#include <vector>

class Panel : public UIElement {
private:
  std::vector<std::shared_ptr<UIElement>> elements;

public:
  Panel(const std::string &name) : UIElement(name) {
    handleInput = [this]() { return this->handleInputImpl(); };
  }

  void AddElement(std::shared_ptr<UIElement> element) {
    elements.push_back(element);
    sortElements();
  }

  void setPanelVisible() {
    this->setVisible();
    for (auto &el : elements) {
      el->setVisible();
    }
  }

  void ClosePanel() { this->setInvisible(); }

  std::shared_ptr<UIElement> getElementByName(std::string _name) {
    for (auto &el : elements) {
      if (el->name == _name) {
        return el;
      }
    }
    return nullptr;
  }

  bool setHandleInput(std::string _name, std::function<bool()> func) {
    auto el = getElementByName(_name);
    if (el == nullptr)
      return false;
    if (func == nullptr) {
      return false;
    }
    el->setHandleInput(func);
    return true;
  }

  void setPanelIndex(int _zIndex) {
    this->zIndex = _zIndex;
    for (auto &el : elements) {
      el->zIndex = _zIndex;
    }
  }

  void sortElements() {
    std::sort(elements.begin(), elements.end(),
              [](const std::shared_ptr<UIElement> &a,
                 const std::shared_ptr<UIElement> &b) {
                return a->zIndex > b->zIndex;
              });
  }

  bool handleInputImpl() {
    for (auto &el : elements) {
      if (el->handleInput()) {
        return true;
      }
    }
    return false;
  }

  // Update all UI elements
  void update() {
    for (auto &el : elements) {
      el->update();
    }
  }

  void render() {
    for (auto &el : elements) {
      if (el->isVisible())
        el->render();
    }
  }
};
