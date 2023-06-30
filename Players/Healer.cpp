//
// Created by Daniella on 15/06/2023.
//

#include "Healer.h"
#include "../utilities.h"

void Healer::heal(int points) {
    this->Player::heal(points*2);
}

void Healer::encounterMana() {
    printManaMessage(true);
    heal(10);
}


std::ostream &Healer::print(std::ostream &os) const {
    printPlayerDetails(os,
                       this->m_name,"Healer",
                       this->m_level,
                       this->m_force,
                       this->m_currentHealth,
                       this->m_coins);
    return os;
}