#pragma once

class GameData;

class Ship {
public:
  Ship() = default;
  int hull = 1;                    // retinue capacity
  int fish_nets = 0;               // food trickle
  int longer_oars = 0;             // speed
  int improved_barrels = 0;        // food capacity
  int square_sails = 0;            // speed
  int carved_dragon_head = 0;      // fame
  int painted_sail = 0;            // fame
  int reinforced_oak_planking = 0; // accidents chance
  int harpoons = 0;                // food trickle

  void ApplyEffects(GameData &gamedata);
};
