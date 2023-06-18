//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_MERCHANT_H
#define EX4_MTM_MERCHANT_H

#include "Card.h"

class Merchant: public Card{
public:
    /*
     * C'tor
     */
    Merchant(): Card(){};


    /*
     *
     */
    void applyEncounter( Player&) const override;

    //Here we are explicitly telling the compiler to use the default/delete methods
    Merchant(const Merchant&)=default;
    Merchant& operator=(const Merchant&) = default;
    ~Merchant()=default;
};


#endif //EX4_MTM_MERCHANT_H
