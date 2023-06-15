//
// Created by Daniella on 15/06/2023.
//

#include "Warrior.h"

int Warrior::getAttackStrength() const {
    return (this->Player::getAttackStrength()*2- this->getLevel());
}
