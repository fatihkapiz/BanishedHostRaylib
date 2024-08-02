#include "Ship.hpp"
#include "GameData.hpp"

void Ship::ApplyEffects(GameData &gamedata) {
  // fish nets
  gamedata.addFood(fish_nets * fish_nets);

  //
}
