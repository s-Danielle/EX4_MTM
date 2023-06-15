//
// Created by Daniella on 13/06/2023.
//
//TODO:
//implement Card class and 6 card type subclasses(battle, Mana, Bar fight, Well, Treasure, Merchant)
//create 3 subclasses for Battle(Gremlin,Witch,Dragon)

#ifndef EX4_MTM_CARD_H
#define EX4_MTM_CARD_H

#include <string>
#include "Player.h"
using std::string;


enum class BattleCardType {Gremlin, Witch, Dragon}; //the type of the battle card

class Card{
private:
    string m_name;
public:
    explicit Card(const string& name) :m_name(name){};
    virtual void applyEncounter(const Player&)=0;

    /*
   * Here we are explicitly telling the compiler to use the default methods
  */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = delete;
};


class BattleCard: Card{
private:
    int m_attackForce;
    int m_loot;
    int m_damage;
public:
    explicit BattleCard(const string& name);
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};

class Merchant: Card{
public:
    explicit Merchant() : Card("Merchant"){};
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};

class Treasure: Card{
public:
    explicit Treasure() : Card("Treasure"){};
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};

class ManaCard: Card{
public:
    explicit ManaCard() : Card("Mana"){};
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};

class Well: Card{
public:
    explicit Well() : Card("Well"){};
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};

class BarFight: Card{
public:
    explicit BarFight() : Card("BarFight"){};
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};
#endif //EX4_MTM_CARD_H
