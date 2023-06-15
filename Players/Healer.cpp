//
// Created by Daniella on 15/06/2023.
//

#include "Healer.h"
void Healer::heal(int points) {
    this->Player::heal(points*2);
}
