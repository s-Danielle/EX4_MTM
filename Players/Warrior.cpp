//
// Created by Daniella on 15/06/2023.
//

#include "Warrior.h"
#include "../utilities.h"

int Warrior::getAttackStrength() const {
    return (this->Player::getAttackStrength()*2- this->getLevel());
}

void Warrior::encounterBarfight() {
    printBarfightMessage(true);
}

std::ostream &Warrior::print(std::ostream &os) const {
    printPlayerDetails(os,
                       this->m_name,"Warrior",
                       this->m_level,
                       this->m_force,
                       this->m_currentHealth,
                       this->m_coins);
    return os;
}

