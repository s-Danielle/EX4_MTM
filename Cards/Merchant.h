//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_MERCHANT_H
#define EX4_MTM_MERCHANT_H

#include "Card.h"

class Merchant: public Card{
public:
    static const int HEAL_COST=5 ;
    static const int BUFF_COST= 10;
    static const int HEAL_AMOUNT= 1;
    static const int BUFF_AMOUNT=1;

    /*
     * C'tor
     */
    explicit Merchant(): Card("Merchant"){};

    /*
     *
     */
    void applyEncounter( Player&) const override;

    //Here we are explicitly telling the compiler to use the default/delete methods
    Merchant(const Merchant&)=default;
    Merchant& operator=(const Merchant&) = default;
    ~Merchant() override=default;
};


#endif //EX4_MTM_MERCHANT_H
