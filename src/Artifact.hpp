#include <functional>
#include <memory>
#include <string>
#include <vector>

class Artifact {
public:
  using EffectFunction = std::function<void()>;
  EffectFunction effect;

  Artifact(std::string name, EffectFunction effect)
      : name(std::move(name)), effect(std::move(effect)) {}

  void ApplyEffect() const { effect(); }
  const std::string &getName() const { return name; }

private:
  std::string name;
};

class ArtifactManager {
public:
  void AddArtifact(std::unique_ptr<Artifact> artifact) {
    artifacts.push_back(std::move(artifact));
  }

  void ApplyEffects() const {
    for (const auto &artifact : artifacts) {
      artifact->ApplyEffect();
    }
  }

  // Add other management functions as needed

private:
  std::vector<std::unique_ptr<Artifact>> artifacts;
};
