#include "Ship.hpp"
#include "Gamedata.hpp"

void Ship::ApplyEffects(GameData &gamedata) {
  // fish nets
  gamedata.addFood(fish_nets * fish_nets);

  //
}
