//
// Created by Daniella on 18/06/2023.
//

#include "Dragon.h"
cardStats Dragon::m_DragonStats() {
    cardStats stats;
    stats.m_loot=DRAGON_LOOT;
    stats.m_damage=DEFAULT_MAX_HP;
    stats.m_force=DRAGON_FORCE;
    return stats;
}
