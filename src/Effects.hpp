#include "Gamedata.hpp"
#include "RandomNumberGenerator.hpp"
#include "json.hpp"
#include <fstream>
#include <string>

using json = nlohmann::json;

class GameData;
class RetinueManager;
class ArtifactManager;

using EffectFunction = std::function<void(GameData &gamedata, int multiplier)>;

class EffectRegistry {
private:
  std::unordered_map<std::string, EffectFunction> effects;

public:
  void RegisterEffects() {
    auto blacksmith_effect = [](GameData &gameData, int multiplier) {
      auto weapon_quality = gameData.retinue->weaponQuality;
      weapon_quality += 0.1 * multiplier;
    };
    registerEffect("blacksmith_effect", blacksmith_effect);

    auto shipbuilder_effect = [](GameData &gameData, int multiplier) {
      int number =
          RandomGenerator::getInstance().getRandomInt(0, 100 / multiplier);
      if (number <= 2) {
        gameData.ship->hull += 1;
      } else if (number > 2 && number < 5) {
        gameData.ship->fish_nets += 1;
      } else if (number >= 5 && number < 10) {
        gameData.ship->harpoons += 1;
      } else if (number >= 10 && number < 15) {
        gameData.ship->improved_barrels += 1;
      }
    };
    registerEffect("shipbuilder_effect", shipbuilder_effect);
  }

  void registerEffect(const std::string &name, EffectFunction effect) {
    effects[name] = std::move(effect);
  }

  EffectFunction getEffect(const std::string &name) {
    auto it = effects.find(name);
    return it != effects.end() ? it->second : nullptr;
  }
};
