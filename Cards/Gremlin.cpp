//
// Created by Daniella on 18/06/2023.
//

#include "Gremlin.h"


cardStats Gremlin::m_GremlinStats() {
    cardStats stats;
    stats.m_loot=GREMLIN_LOOT;
    stats.m_damage=GREMLIN_DAMAGE;
    stats.m_force=GREMLIN_FORCE;
    return stats;
}
