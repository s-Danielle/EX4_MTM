//
// Created by Daniella on 13/06/2023.
//


#ifndef EX4_MTM_CARD_H
#define EX4_MTM_CARD_H

#include <string>
#include <map>
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

class Card{
protected:
    std::string m_name;

    explicit Card(const std::string& name): m_name(name){};
public:
    typedef Card* (*createFunction)(); //TODO: what is this???
    /**
     *
     * initializes the factory map
     */
    static std::map<std::string, createFunction>& GetCardMap();
    /**
     *
     * @param name -name of the requested card
     * @return pointer to the new card
     * user is responsible to delete object
     * in case of invalid string throws exception
     */
     static Card* createFromString(const std::string& name);

    /*
     * handles the encounter with player
     * each card has a different behavior
     */
    virtual void applyEncounter( Player&) const=0;

    /*
     * TODO figure hoe to print
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    //Here we are explicitly telling the compiler to use the default/delete methods:
    virtual ~Card()=default;
};

#endif //EX4_MTM_CARD_H