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

Card* createNewCard(const std::string &type) {
    /**this is basically a factory method.
     *  maybe we should consider making it its own class/header, or static if not.
     * see my note on return value.
     * the map idea was good. i hate this course so much.
     */
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
    throw InvalidInput();
}

std::ostream &Card::print(std::ostream &os) const {
    printCardDetails(os, this->m_name);
    return os;
}
std::ostream& operator<<(std::ostream& os, const Card& card){
    card.print(os);
    return os;
}
