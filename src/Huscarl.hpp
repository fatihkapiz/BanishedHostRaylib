#include "Trait.hpp"
#include "raylib.h"
#include <functional>
#include <string>

class Huscarl {

private:
  std::string name;
  Trait trait;
  Texture2D texture;

public:
  using EffectFunction = std::function<void()>;
  EffectFunction effect;

  ~Huscarl() { UnloadTexture(texture); }
  Huscarl(std::string name, EffectFunction effect, const char *_image)
      : name(std::move(name)), effect(std::move(effect)) {
    Image image = LoadImage(_image);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
  }

  void ApplyEffects() { effect(); }
  const std::string &getName() const { return name; }
  const Texture2D &getTexture() { return texture; }
};
