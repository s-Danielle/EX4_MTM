//
// Created by Daniella on 18/06/2023.
//

#include "Dragon.h"
#include "../utilities.h"

Battle::CardStats Dragon::getDragonStats() {
    Battle::CardStats stats={};
    stats.m_loot=Dragon::DRAGON_LOOT;
    stats.m_damage=Player::DEFAULT_MAX_HP;
    stats.m_force=Dragon::DRAGON_FORCE;
    return stats;
}

std::ostream &Dragon::print(std::ostream &os) const {
    printCardDetails(os, this->m_name);
    printMonsterDetails(os, this->m_stats.m_force, this->m_stats.m_damage, this->m_stats.m_loot, true);
    printEndOfCardDetails(os);
    return os;
}