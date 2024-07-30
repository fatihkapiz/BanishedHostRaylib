#include "json.hpp"
#include <string>

using json = nlohmann::json;

class Trait {
public:
  std::string name;
  std::string description;
  float rarity;
  std::string effect;

  static Trait fromJson(const json &j) {
    return Trait{j["name"].get<std::string>(),
                 j["decription"].get<std::string>(), j["rarity"].get<float>(),
                 j["effect"].get<std::string>()};
  }
};
