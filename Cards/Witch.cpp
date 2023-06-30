//
// Created by Daniella on 18/06/2023.
//

#include "Witch.h"
#include "../utilities.h"

Battle::CardStats Witch::getWitchStats() {
    Battle::CardStats stats{};
    stats.m_loot=Witch::WITCH_LOOT;
    stats.m_damage=Witch::WITCH_DAMAGE;
    stats.m_force=Witch::WITCH_FORCE;
    return stats;
}

void Witch::applyEncounter(Player &player) const {
    if(player.getAttackStrength()<m_stats.m_force){
        player.damage(m_stats.m_damage);
        player.buff(-1);
        printLossBattle(player.getName(),m_name);
    }
    else{
        player.addCoins(m_stats.m_loot);
        player.levelUp();   //important
        printWinBattle(player.getName(),m_name);
    }
}