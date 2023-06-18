//
// Created by Daniella on 17/06/2023.
//

#include "Mana.h"
#include "../utilities.h"

void Mana::applyEncounter(Player &player) const {
    printManaMessage(player.getClass()=="Healer");
    if (player.getClass()=="Healer"){
        player.heal(10);
    }
}
