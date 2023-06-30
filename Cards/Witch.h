//
// Created by Daniella on 18/06/2023.
//

#ifndef EX4_MTM_WITCH_H
#define EX4_MTM_WITCH_H
#include "Battle.h"

class Witch :public Battle{

private:
    static const int WITCH_FORCE= 11;
    static const int WITCH_DAMAGE= 10;
    static const int WITCH_LOOT= 2;

public:
    /*
     * initializes stats
     */
    static Battle::CardStats getWitchStats();
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
