#include "raylib.h"
#include <functional>
#include <string>
class Huscarl {
  using EffectFunction = std::function<void()>;

private:
  std::string name;
  EffectFunction effect;
  Texture2D texture;

public:
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
