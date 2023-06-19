//
// Created by Daniella on 13/06/2023.
//

#include "Card.h"
#include "../utilities.h"
#include "Witch.h"
#include "Barfight.h"
#include "Dragon.h"
#include "Mana.h"
#include "Gremlin.h"
#include "Merchant.h"
#include "Well.h"
#include "Treasure.h"

using std::map;
using std::string;


map<string, Card::createFunction>& Card::GetCardMap() {
    static map<string, createFunction> CardFactoryMap;
    return CardFactoryMap;
}

Card *Card::createFromString(const string &name) {
    auto& CardFactoryMap= GetCardMap();
    auto functionIndex= CardFactoryMap.find(name);
    if(functionIndex == CardFactoryMap.end()){
        throw std::exception();//TODO specify
    }
    return (functionIndex->second)();
}


std::ostream& operator<<(std::ostream& os, const Card& card){
    printCardDetails(os,card.m_name);
    printEndOfCardDetails(os);
    return os;
}