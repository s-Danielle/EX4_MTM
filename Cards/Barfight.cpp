//
// Created by Daniella on 17/06/2023.
//

#include "Barfight.h"
#include "../utilities.h"

void Barfight::applyEncounter(Player &player) const {
    if(player.getClass()=="Warrior"){
        return;
    }
    player.damage(10);
}

