//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_GREMLIN_H
#define EX4_MTM_GREMLIN_H

#include "../Battle.h"
#define HP_ON_LOSS 10
#define LOOT 4
#define FORCE 4

class Gremlin :public Battle{
public:
    Gremlin(): Battle(FORCE,HP_ON_LOSS,LOOT){};
};


#endif //EX4_MTM_GREMLIN_H
