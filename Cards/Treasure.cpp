//
// Created by Daniella on 17/06/2023.
//

#include "Treasure.h"
#include "../utilities.h"

void Treasure::applyEncounter(Player &player) const {
    printTreasureMessage();
    player.addCoins(10);
}
