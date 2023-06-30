//
// Created by Daniella on 18/06/2023.
//

#include "Gremlin.h"


Battle::CardStats Gremlin::getGremlinStats() {
    Battle::CardStats stats{};
    stats.m_loot=Gremlin::GREMLIN_LOOT;
    stats.m_damage=Gremlin::GREMLIN_DAMAGE;
    stats.m_force=Gremlin::GREMLIN_FORCE;
    return stats;
}
