//
// Created by Daniella on 17/06/2023.
//

#ifndef EX4_MTM_BATTLE_H
#define EX4_MTM_BATTLE_H


#include "Card.h"
using std::string;

enum class MonsterType {Dragon, Witch, Gremlin }; //the type of the Monster
MonsterType  MonsterType(const string& type);

class Battle: public Card{
protected:
    string m_name;
    int m_force;
    int m_damage;
    int m_loot;
    Battle(const string &name, int force, int damage, int loot):
           Card(name),
           m_name(name),
           m_force(force),
           m_damage(damage),
           m_loot(loot){};
public:

    /**
     * C'tor of battle Card
     * @param type use BattleCard(string type) for safe use- will throw exception
     * returns new instance
     */
    explicit Battle(const std::string& name);

    /**
     *
     */
    void applyEncounter(Player &)  const override;

    friend std::ostream& operator<<(std::ostream& os, const Battle& card);
    //TODO i can't override here are we sure its gonna choose this function? ^
    /*
     * Here we tell the compiler to use default functions:
     */
    Battle& operator=(const Battle&)=default;
    Battle(const Battle&)=default;
    ~Battle()=default;
};


#endif //EX4_MTM_BATTLE_H
