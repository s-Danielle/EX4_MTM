//
// Created by Daniella on 18/06/2023.
//

#include "Dragon.h"
#include "../utilities.h"

CardStats Dragon::getDragonStats() {
    CardStats stats={Dragon::DRAGON_FORCE,Player::DEFAULT_MAX_HP,Dragon::DRAGON_LOOT};
//    stats.m_loot=;
//    stats.m_damage=;
//    stats.m_force=;
    return stats;
}

std::ostream &Dragon::print(std::ostream &os) const {
    printMonsterDetails(os,this->m_stats.m_force,this->m_stats.m_damage, this->m_stats.m_loot, true);
    return os;
}