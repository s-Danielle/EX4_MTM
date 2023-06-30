//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_BATTLE_H
#define EX4_MTM_BATTLE_H

#include "Card.h"

class Battle: public Card{

protected:
    struct CardStats{
        int m_force;
        int m_damage;
        int m_loot;
    };
    CardStats m_stats;
    /**
     * C'tor of battle Card
     * @param type use BattleCard(string type) for safe use- will throw exception
     * returns new instance
     */
    Battle(const std::string &name, CardStats stats):
           Card(name),
           m_stats(stats){};
public:
    /**
     *handles the fight encounter-
     * if player force is lesser than monster force player will lose
     * on Win-player will gain loot
     * on Loss-player will receive damage
     */
    virtual void applyEncounter(Player &)  const override;

    virtual std::ostream& print(std::ostream& os) const override;

    /*
     * Here we tell the compiler to use default/delete functions:
     */

    Battle& operator=(const Battle&)=delete;
    Battle(const Battle&)=delete;
    ~Battle() override=default;
};


#endif //EX4_MTM_BATTLE_H
