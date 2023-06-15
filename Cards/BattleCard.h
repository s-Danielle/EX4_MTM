//
// Created by Daniella on 16/06/2023.
//

#ifndef EX4_MTM_BATTLECARD_H
#define EX4_MTM_BATTLECARD_H

#include "Card.h"
#include "../Players/Player.h"

class BattleCard: public Card{
private:
    int m_attackForce;
    int m_loot;
    int m_damage;
public:
    explicit BattleCard(BattleCardType type);
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};


#endif //EX4_MTM_BATTLECARD_H
