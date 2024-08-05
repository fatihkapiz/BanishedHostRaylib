#pragma once
#include "Artifact.hpp"
#include "HuscarlManager.hpp"
#include "Retinue.hpp"
#include "Ship.hpp"
#include <memory>

class GameData {
public:
  /*
  static GameData &getInstance() {
    static GameData instance;
    return instance;
  }
  */

  GameData(const GameData &) = delete;
  GameData &operator=(const GameData &) = delete;

  int getGold() const { return Gold; }
  void setGold(int amount) { Gold = amount; }
  void addGold(int amount) { Gold += amount; }

  int getFame() const { return Fame; }
  void setFame(int amount) { Fame = amount; }
  void addFame(int amount) { Fame += amount; }

  float getFood() const { return Food; }
  void setFood(float amount) { Food = amount; }
  void addFood(float amount) { Food += amount; }

  int getLoot() const { return Loot; }
  void setLoot(int amount) { Loot = amount; }
  void addLoot(int amount) { Loot += amount; }

  void ApplyEffects() { retinue->ApplyEffects(*this); }

  GameData() {
    retinue = std::make_unique<Retinue>();
    ship = std::make_unique<Ship>();
    artifactManager = std::make_unique<ArtifactManager>();
    huscarlManager = std::make_unique<HuscarlManager>();
  };

  int Gold = 10;
  float Food = 10;
  int Fame = 10;
  int Loot = 10;
  int RetinueCapacity;
  std::unique_ptr<Retinue> retinue;
  std::unique_ptr<HuscarlManager> huscarlManager;
  std::unique_ptr<Ship> ship;
  std::unique_ptr<ArtifactManager> artifactManager;
};
