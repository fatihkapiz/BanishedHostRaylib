#pragma once
#include "GameData.hpp"

class Ship {
public:
  int hull = 1;
  int fish_nets = 0;
  int longer_oars = 0;
  int improved_barrels = 0;
  int square_sails = 0;
  int carved_dragon_head = 0;
  int painted_sail = 0;
  int reinforced_oak_planking = 0;
  int harpoons = 0;

  void ApplyEffects();
};

inline void Ship::ApplyEffects() { Gamedata::addFood(fish_nets * fish_nets); }