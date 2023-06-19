//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_WELL_H
#define EX4_MTM_WELL_H
#include "Card.h"

class Well: public Card{
public:
    /*
     * C'tor
     */
    explicit Well(): Card("Well"){};

    /*
     *damages 10 points unless Ninja player
     */
    void applyEncounter( Player&) const override;

    //Here we are explicitly telling the compiler to use the default/delete methods
    Well(const Well&)=default;
    Well& operator=(const Well&) = default;
    ~Well() override=default;
};

#endif //EX4_MTM_WELL_H
