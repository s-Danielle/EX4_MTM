//
// Created by Daniella on 18/06/2023.
//

#include "Witch.h"

cardStats Witch::getWitchStats() {
    cardStats stats;
    stats.m_loot=WITCH_LOOT;
    stats.m_damage=WITCH_DAMAGE;
    stats.m_force=WITCH_FORCE;
    return stats;
}
