#include <functional>
#include <string>

class Artifact {
public:
  using EffectFunction = std::function<void()>;

  Artifact(std::string name, EffectFunction effect)
      : name(std::move(name)), effect(std::move(effect)) {}

  void ApplyEffects() const { effect(); }

  const std::string &getName() const { return name; }

private:
  std::string name;
  EffectFunction effect;
};
