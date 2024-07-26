#include "Huscarl.hpp"
#include "raylib.h"
#include <memory>
#include <string>
#include <vector>

class HuscarlManager {
private:
  std::vector<std::unique_ptr<Huscarl>> huscarls;

public:
  void AddHuscarl(std::string name, Huscarl::EffectFunction effect,
                  const char *image) {
    huscarls.push_back(
        std::make_unique<Huscarl>(std::move(name), std::move(effect), image));
  }

  void ApplyEffects() {
    for (const auto &huscarl : huscarls) {
      huscarl->ApplyEffect();
    }
  }

  const Huscarl *GetHuscarlByName(const std::string &name) const {
    auto it =
        std::find_if(huscarls.begin(), huscarls.end(),
                     [&name](const auto &h) { return h->getName() == name; });
    return it != huscarls.end() ? it->get() : nullptr;
  }

  void RemoveHuscarl(const std::string &name) {
    huscarls.erase(
        std::remove_if(huscarls.begin(), huscarls.end(),
                       [&name](const auto &h) { return h->getName() == name; }),
        huscarls.end());
  }

  size_t GetHuscarlCount() const { return huscarls.size(); }

  const Huscarl *GetHuscarlAt(size_t index) const {
    return index < huscarls.size() ? huscarls[index].get() : nullptr;
  }
};
