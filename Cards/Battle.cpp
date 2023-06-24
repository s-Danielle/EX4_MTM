//
// Created by Daniella on 17/06/2023.
//

#include "Battle.h"
#include "../utilities.h"


void Battle::applyEncounter( Player & player) const {

    if(player.getAttackStrength()<m_stats.m_force){
        player.damage(m_stats.m_damage);
        printLossBattle(player.getName(),m_name);
    }
    else{
        player.addCoins(m_stats.m_loot);
        printWinBattle(player.getName(),m_name);
    }
}

std::ostream &Battle::print(std::ostream &os) const {
    printMonsterDetails(os,this->m_stats.m_force,this->m_stats.m_damage, this->m_stats.m_loot);
    return os;
}
