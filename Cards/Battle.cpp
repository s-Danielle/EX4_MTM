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

Battle::Battle(const std::string& name): Card(name) {
    enum MonsterType type=MonsterType(name);
    switch (type) {
        case MonsterType::Witch:
            *this=Battle("Witch",12,10,3);
        case MonsterType::Dragon:
            *this=Battle("Dragon",25,DEFAULT_MAX_HP,1000);
        case MonsterType::Gremlin:
            *this=Battle("Gremlin",7,10,3);
    }
}

void Battle::applyEncounter( Player & player) const {

    if(player.getAttackStrength()<m_force){
        player.damage(m_damage);
        printLossBattle(player.getName(),m_name);
    }
    else{
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
}

std::ostream& operator<<(std::ostream& os, const Battle& card){
    printMonsterDetails(os,card.m_force,card.m_damage, card.m_loot,card.m_name=="Dragon");
    //TODO check if i need print end of card
    return os;
}