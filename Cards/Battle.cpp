//
// Created by Daniella on 17/06/2023.
//

#include "Battle.h"
#include "../utilities.h"

enum MonsterType MonsterType(const string& type){
    if (type=="Witch"){
        return MonsterType::Witch;
    }
    if (type=="Gremlin"){
        return MonsterType::Gremlin;
    }
    if (type=="Dragon"){
        return MonsterType::Dragon;
    }
    throw std::exception();//TODO throw the right exception here

}


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

std::ostream& operator<<(std::ostream& os, const Battle& card){
    printMonsterDetails(os,card.m_stats.m_force,card.m_stats.m_damage, card.m_stats.m_loot);
    //TODO check if i need print end of card
    //I need to override this somehow ??
    return os;
}

