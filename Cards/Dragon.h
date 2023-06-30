//
// Created by Daniella on 18/06/2023.
//

#ifndef EX4_MTM_DRAGON_H
#define EX4_MTM_DRAGON_H

#include "Battle.h"


class Dragon : public Battle{
private:
    static const int DRAGON_FORCE =25;
    static const int DRAGON_LOOT=1000;
    /*
     * initializes stats
     */

public:
    static CardStats getDragonStats();
    /**
     * C'tor
     * new instance of Dragon Card
     */
    explicit Dragon(): Battle("Dragon", getDragonStats()){};


    /*
     *overriding print function
     */
    std::ostream& print(std::ostream& os) const override;

    /*
     * Here we tell the compiler to use default/delete functions:
     */
    Dragon& operator=(const Dragon&)=delete;
    Dragon(const Dragon&)=delete;
    ~Dragon() override=default;
};


#endif //EX4_MTM_DRAGON_H
