//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_MANA_H
#define EX4_MTM_MANA_H

#include "Card.h"

class Mana: public Card{
public:
    /*
     * C'tor
     */
    explicit Mana(): Card("Mana"){};

    /**
     *if player is healer class this card allows him to heal 10 points
     */
    void applyEncounter(Player &) const override;


    //Here we are explicitly telling the compiler to use the default/delete methods
    Mana(const Mana&)=default;
    Mana& operator=(const Mana&) = default;
    ~Mana() override=default;
};


#endif //EX4_MTM_MANA_H
