#pragma once

class IClickable {
private:
public:
  virtual ~IClickable() = default; // Virtual destructor for proper cleanup
  virtual void handleInput() = 0;
};
