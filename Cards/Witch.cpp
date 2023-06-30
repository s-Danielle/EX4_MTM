//
// Created by Daniella on 18/06/2023.
//

#include "Witch.h"

cardStats Witch::getWitchStats() {
    cardStats stats;
    stats.m_loot=Witch::WITCH_LOOT;
    stats.m_damage=Witch::WITCH_DAMAGE;
    stats.m_force=Witch::WITCH_FORCE;
    return stats;
}
