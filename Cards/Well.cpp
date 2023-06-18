//
// Created by Daniella on 17/06/2023.
//

#include "Well.h"
#include "../utilities.h"

void Well::applyEncounter(Player &player) const {
    printWellMessage(player.getClass()=="Ninja");
    if(player.getClass()=="Ninja"){
        return;
    }
    player.damage(10);
}

