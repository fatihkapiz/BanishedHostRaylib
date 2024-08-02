#include "Retinue.hpp"
#include "GameData.hpp"

void Retinue::ConsumeFood(GameData &gamedata) { gamedata.addFood(-men * 0.02); }
void Retinue::ApplyEffects(GameData &gamedata) { ConsumeFood(gamedata); }
