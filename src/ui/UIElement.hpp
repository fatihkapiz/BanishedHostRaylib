#pragma once
#include <functional>
#include <string>

class UIElement {
private:
  bool visible;

public:
  std::string name;
  int zIndex;
  std::function<bool()> handleInput; // Function to handle input

  UIElement(const std::string name)
      : name(name), visible(false), zIndex(0), handleInput(nullptr) {}
  virtual ~UIElement() = default;

  void setHandleInput(const std::function<bool()> &func) { handleInput = func; }
  virtual void update() = 0;
  virtual void render() = 0;
  void setVisible() { visible = true; }
  void setInvisible() { visible = false; }
  bool isVisible() { return visible; }
};
