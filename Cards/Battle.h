//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_BATTLE_H
#define EX4_MTM_BATTLE_H


#include <map>

#include "Card.h"
using std::string;

enum class MonsterType {Dragon, Witch, Gremlin }; //the type of the Monster
MonsterType  MonsterType(const string& type);


struct cardStats{
    int m_force;
    int m_damage;
    int m_loot;
}typedef cardStats;



class Battle: public Card{
protected:
    cardStats m_stats;
    /**
     * C'tor of battle Card
     * @param type use BattleCard(string type) for safe use- will throw exception
     * returns new instance
     */
    Battle(const string &name, cardStats stats):
           Card(name),
           m_stats(stats){};
public:
    /**
     *handles the fight encounter-
     * if player force is lesser than monster force player will lose
     * on Win-player will gain loot
     * on Loss-player will receive damage
     */
    void applyEncounter(Player &)  const override;

    friend std::ostream& operator<<(std::ostream& os, const Battle& card);
    //TODO i can't override here are we sure its gonna choose this function? ^

    /*
     * Here we tell the compiler to use default/delete functions:
     */
    Battle& operator=(const Battle&)=delete;
    Battle(const Battle&)=delete;
    ~Battle() override=default;
};


#endif //EX4_MTM_BATTLE_H
