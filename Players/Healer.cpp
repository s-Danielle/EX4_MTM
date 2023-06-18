//
// Created by Daniella on 15/06/2023.
//

#include "Healer.h"
#include "../utilities.h"

void Healer::heal(int points) {
    this->Player::heal(points*2);
}


std::string Healer::getClass() const {
    return "Healer";
}
