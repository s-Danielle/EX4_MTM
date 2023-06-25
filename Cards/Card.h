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

    /**
     * C'tor
     * @param name is basically card type-not up to user.
     */
    explicit Card(const std::string& name): m_name(name){};
public:

    /*
     * for user ease-creates new card from string,
     * if no matching card will throw an exception
     */
    Card* createNewCard(const string& type);

    /*
     * handles the encounter with player
     * each card has a different behavior
     */
    virtual void applyEncounter( Player&) const=0;

    /*
     * default print function using utilities.h
     */
    virtual std::ostream& print(std::ostream& os) const;

    //Here we are explicitly telling the compiler to use the default/delete methods:
    Card& operator=(const Card&)=default;
    Card(const Card&)=default;
    virtual ~Card()=default;


    //overloading operator >>
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif //EX4_MTM_CARD_H

