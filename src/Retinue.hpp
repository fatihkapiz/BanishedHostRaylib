#pragma once

class GameData;

class Retinue {
public:
  Retinue(){};

  float experience = 0.5f;

  int capacity = 30;
  int Axemen = 10;
  int Swordsmen = 5;
  int TwoHandedSwordsmen = 0;
  int Spearmen = 5;
  int Bowmen = 5;
  int men = Axemen + Swordsmen + TwoHandedSwordsmen + Spearmen + Bowmen;

  int weapons = 10;
  float weaponQuality = 0.3f;

  float armorWeight = 0.30f;
  float armorQuality = 0.30f;

  void ApplyEffects(GameData &gamedata);
  void ConsumeFood(GameData &gamedata);
};
