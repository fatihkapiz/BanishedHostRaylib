#pragma once
#include "Gold.hpp"
#include <string>
#include <unordered_map>

class UI {
private:
  std::unordered_map<std::string, std::unique_ptr<UIElement>> elements;

public:
  UI() {}

  template <typename T, typename... Args>
  void addElement(const std::string &name, Args &&...args) {
    elements[name] = std::make_unique<T>(std::forward<Args>(args)...);
  }

  void removeElement(const std::string &name) {
    auto it = elements.find(name);
    if (it != elements.end()) {
      elements.erase(it);
    }
  }

  UIElement *getElement(const std::string &name) {
    auto it = elements.find(name);
    if (it != elements.end()) {
      return it->second.get();
    }
    return nullptr;
  }

  // Update all UI elements
  void update() {
    for (auto &pair : elements) {
      pair.second->update();
    }
  }

  void render() {
    for (auto &pair : elements) {
      pair.second->render();
    }
  }
};
