#pragma once
#include "IClickable.hpp"
#include "UIElement.hpp"

class ClickableUIElement : public UIElement, public IClickable {
public:
  ClickableUIElement(std::string name) : UIElement(name) {}
  virtual ~ClickableUIElement() =
      default; // Virtual destructor for proper cleanup
};
