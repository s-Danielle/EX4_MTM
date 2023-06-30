//
// Created by Daniella on 18/06/2023.
//

#include "Dragon.h"
#include "../utilities.h"

cardStats Dragon::m_DragonStats() {
    cardStats stats;
    stats.m_loot=Dragon::DRAGON_LOOT;
    stats.m_damage=Player::DEFAULT_MAX_HP;
    stats.m_force=Dragon::DRAGON_FORCE;
    return stats;
}

std::ostream &Dragon::print(std::ostream &os) const {
    printMonsterDetails(os,this->m_stats.m_force,this->m_stats.m_damage, this->m_stats.m_loot, true);
    return os;
}