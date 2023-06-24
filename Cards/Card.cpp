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


using std::string;

Card *Card::createNewCard(const std::string &type) {
    if (type == "Barfight") {
        return new Barfight();
    }
    if (type=="Mana") {
        return new Mana();
    }
    if (type=="Well") {
        return new Well();
    }
    if (type=="Dragon") {
        return new Dragon();
    }
    if (type=="Gremlin") {
        return new Gremlin();
    }
    if (type=="Witch") {
        return new Witch();
    }
    if (type=="Merchant") {
        return new Merchant();
    }
    if (type=="Treasure") {
        return new Treasure();
    }
    throw std::exception();//TODO specify
}

std::ostream &Card::print(std::ostream &os) const {
    printCardDetails(os, this->m_name);
    return os;
}
std::ostream& operator>>(std::ostream& os, const Card& card){
    card.print(os);
    return os;
}


//
//map<string, Card::createFunction>& Card::GetCardMap() {
//    static map<string, createFunction> CardFactoryMap;
//    return CardFactoryMap;
//}
//
//Card *Card::createFromString(const string &name) {
//    auto& CardFactoryMap= GetCardMap();
//    auto functionIndex= CardFactoryMap.find(name); // finds by key
//    if(functionIndex == CardFactoryMap.end()){ //checks if inside
//        throw std::exception();//TODO specify
//    }
//    return (functionIndex->second)(); //returns the value
//}
