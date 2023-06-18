//
// Created by Daniella on 13/06/2023.
//

#include "Card.h"
#include "Battle.h"
#include "../utilities.h"
enum CardType CardType(const string& type){
    if(type=="Treasure"){
        return CardType::Treasure;
    }
    if(type=="Mana"){
        return CardType::Mana;
    }
    if(type=="Merchant"){
        return CardType::Merchant;
    }
    if(type=="Well"){
        return CardType::Well;
    }
    if(type=="Barfight" ){
        return CardType::BarFight;
    }
    MonsterType(type);//will throw exception
    return CardType::Battle;
}

std::ostream& operator<<(std::ostream& os, const Card& card){
    printCardDetails(os,card.m_name);
    printEndOfCardDetails(os);
    return os;
}