#pragma once
#include "Artifact.hpp"
#include "Huscarl.hpp"
#include "Retinue.hpp"
#include "Ship.hpp"
#include <memory>
#include <vector>

class Ship;

namespace Gamedata {

inline int Gold = 10;
inline float Food = 10;
inline int Fame = 10;
inline int Loot = 10;
inline std::unique_ptr<Retinue> retinue;
inline std::unique_ptr<Ship> ship;

inline int getGold() { return Gold; }
inline void setGold(int amount) { Gold = amount; }
inline void addGold(int amount) { Gold += amount; }
inline int getFame() { return Fame; }
inline void setFame(int amount) { Fame = amount; }
inline void addFame(int amount) { Fame += amount; }
inline int getFood() { return Food; }
inline void setFood(float amount) { Food = amount; }
inline void addFood(float amount) { Food += amount; }
inline int getLoot() { return Loot; }
inline void setLoot(int amount) { Loot = amount; }
inline void addLoot(int amount) { Loot += amount; }

inline std::vector<Huscarl> huscarls;
inline std::vector<Artifact> artifacts;

inline void addHuscarl(Huscarl huscarl) { huscarls.push_back(huscarl); }

inline void addArtifact(Artifact artifact) { artifacts.push_back(artifact); }

inline void ApplyEffects() {
  if (retinue) {
    retinue->ApplyEffects();
  }
  if (ship) {
    ship->ApplyEffects();
  }
  for (auto &art : artifacts) {
    art.ApplyEffects();
  }
  for (auto &huscarl : huscarls) {
    huscarl.ApplyEffects();
  }
}

inline void Initialize() {
  retinue = std::make_unique<Retinue>();
  ship = std::make_unique<Ship>();
}
} // namespace Gamedata
