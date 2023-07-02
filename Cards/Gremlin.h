//
// Created by Daniella on 18/06/2023.
//

#ifndef EX4_MTM_GREMLIN_H
#define EX4_MTM_GREMLIN_H
#include "Battle.h"

class Gremlin : public Battle{
private:
    static const int GREMLIN_FORCE= 5;//TODO: put it back to 5 after testing
    static const int GREMLIN_DAMAGE =10;
    static const int GREMLIN_LOOT= 2;
public:
    /*
     * initializes stats
     */
    static CardStats getGremlinStats();
    /**
     * C'tor
     * @param name card name
     * new instance of Gremlin Card
     */
    explicit Gremlin(): Battle("Gremlin", getGremlinStats()){};

    /*
     * Here we tell the compiler to use default/delete functions:
     */
    Gremlin& operator=(const Gremlin&)=delete;
    Gremlin(const Gremlin&)=delete;
    ~Gremlin() override=default;
};


#endif //EX4_MTM_GREMLIN_H
