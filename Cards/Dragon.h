//
// Created by Daniella on 18/06/2023.
//

#ifndef EX4_MTM_DRAGON_H
#define EX4_MTM_DRAGON_H

#include "Battle.h"

#define DRAGON_FORCE 7
#define DRAGON_LOOT 3


class Dragon : public Battle{
private:
    /*
     * initializes stats
     */
    static cardStats m_DragonStats();
public:

    /**
     * C'tor
     * @param name card name
     * new instance of Dragon Card
     */
    explicit Dragon(): Battle("Dragon", m_DragonStats()){};

    /*
     * Here we tell the compiler to use default/delete functions:
     */
    Dragon& operator=(const Dragon&)=delete;
    Dragon(const Dragon&)=delete;
    ~Dragon() override=default;
};


#endif //EX4_MTM_DRAGON_H
