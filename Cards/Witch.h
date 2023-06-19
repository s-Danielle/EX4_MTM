//
// Created by Daniella on 18/06/2023.
//

#ifndef EX4_MTM_WITCH_H
#define EX4_MTM_WITCH_H
#include "Battle.h"

#define WITCH_FORCE 12
#define WITCH_DAMAGE 10
#define WITCH_LOOT 3


class Witch :public Battle{
private:
    /*
     * initializes stats
     */
    static cardStats getWitchStats();
public:

    /**
     * C'tor
     * @param name card name
     * new instance of Dragon Card
     */
    explicit Witch(): Battle("Witch", getWitchStats()){};


    /*
     * Here we tell the compiler to use default/delete functions:
     */
    Witch& operator=(const Witch&)=delete;
    Witch(const Witch&)=delete;
    ~Witch() override=default;

};


#endif //EX4_MTM_WITCH_H
