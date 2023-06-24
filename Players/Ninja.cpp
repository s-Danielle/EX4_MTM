//
// Created by Daniella on 15/06/2023.
//

#include "Ninja.h"
#include "../utilities.h"

void Ninja::addCoins(int coinAmount) {
    this->Player::addCoins(coinAmount*2);
}

void Ninja::encounterWell() {   //override??
    printWellMessage(true);
//Do nothing
}

std::ostream &Ninja::print(std::ostream &os) const {
    printPlayerDetails(os,
                       this->m_name,"Ninja",
                       this->m_level,
                       this->getAttackStrength(),
                       this->m_currentHealth,
                       this->m_coins);
    return os;
}
