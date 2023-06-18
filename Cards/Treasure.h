//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_TREASURE_H
#define EX4_MTM_TREASURE_H
#include "Card.h"
class Treasure: public Card{
public:
    /*
     * C'tor
     */
    Treasure(): Card(){};

    /*
     *
     */
    void applyEncounter( Player&) const override;

    //Here we are explicitly telling the compiler to use the default/delete methods
    Treasure(const Treasure&)=default;
    Treasure& operator=(const Treasure&) = default;
    ~Treasure() override =default;
};

#endif //EX4_MTM_TREASURE_H
