//
// Created by Daniella on 13/06/2023.
//
//TODO:
//implement Card class and 6 card type subclasses(battle, Mana, Bar fight, Well, Treasure, Merchant)
//create 3 subclasses for Battle(Gremlin,Witch,Dragon)

#ifndef EX4_MTM_CARD_H
#define EX4_MTM_CARD_H

#include <string>
#include "../Players/Player.h"

using std::string;


enum class BattleCardType {Gremlin, Witch, Dragon}; //the type of the battle card

class Card{
public:
    virtual void applyEncounter(const Player&)=0;
    /*
   * Here we are explicitly telling the compiler to use the default methods
  */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = delete;
    //TODO add operator <<
};




class Merchant: public Card{
public:
    explicit Merchant();
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};

class Treasure: public Card{
public:
    explicit Treasure();
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};

class ManaCard: public Card{
public:
    explicit ManaCard();
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};

class Well: public Card{
public:
    explicit Well();
    /*
    * Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
   */
    void applyEncounter(const Player&) override;
};

class BarFight: public Card{
public:
    explicit BarFight();
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
