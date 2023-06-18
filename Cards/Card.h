//
// Created by Daniella on 13/06/2023.
//


#ifndef EX4_MTM_CARD_H
#define EX4_MTM_CARD_H

#include <string>
#include "../Players/Player.h"

using std::string;

/**
 * CARD TYPES:
 *
 * MERCHANT-
 *
 * Treasure-
 *
 * Battle-
 *
 * Mana-
 *
 * Well-
 *
 * Well-
 *
 */
enum class CardType {Battle, Mana, Merchant, Well, Treasure, BarFight }; //the type of the card
/*
 * this function converts a string to Card type
 * if no match is found an exception is thrown
 */
CardType CardType(const string& type);



class Card{
protected:
    std::string m_name;
    explicit Card(const std::string& name=""): m_name(name){};
public:
    /*
     * handles the encounter with player
     * each card has a different behavior
     */
    virtual void applyEncounter( Player&) const=0;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    static Card* creatNewCard(string name);

    //Here we are explicitly telling the compiler to use the default/delete methods:
    virtual ~Card()=default;
};

#endif //EX4_MTM_CARD_H