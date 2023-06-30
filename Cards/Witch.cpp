//
// Created by Daniella on 18/06/2023.
//

#include "Witch.h"

Battle::CardStats Witch::getWitchStats() {
    Battle::CardStats stats{Witch::WITCH_FORCE,Witch::WITCH_DAMAGE, Witch::WITCH_LOOT};
//    stats.m_loot=;
//    stats.m_damage=;
//    stats.m_force=;
    return stats;
}
