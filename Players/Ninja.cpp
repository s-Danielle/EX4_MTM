//
// Created by Daniella on 15/06/2023.
//

#include "Ninja.h"
#include "../utilities.h"

void Ninja::addCoins(int coinAmount) {
    this->Player::addCoins(coinAmount*2);
}

void Ninja::encounterWell() {
    printWellMessage(true);
//Do nothing
}