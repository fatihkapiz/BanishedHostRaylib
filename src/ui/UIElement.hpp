#pragma once
#include "raylib.h"
#include <string>

class UIElement {
private:
  bool active;

public:
  std::string name;
  UIElement(const std::string name) : name(name) { active = false; }
  virtual ~UIElement() = default;

  virtual void onClick() = 0;
  virtual void update() = 0;
  virtual void render() = 0;
};
