//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_BARFIGHT_H
#define EX4_MTM_BARFIGHT_H


#include "Card.h"

class Barfight: public Card{
public:

    static const int BARFIGHT_DAMAGE=10;
    /*
     * C'tor
     */
    explicit Barfight(): Card("Barfight"){};

    /*
     *
     */
    void applyEncounter( Player&) const override;

    //Here we are explicitly telling the compiler to use the default/delete methods
    Barfight(const Barfight&)=default;
    Barfight& operator=(const Barfight&) = default;
    ~Barfight() override=default;
};


#endif //EX4_MTM_Barfight_H
