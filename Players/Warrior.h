//
// Created by Daniella on 15/06/2023.
//

#ifndef EX4_MTM_WARRIOR_H
#define EX4_MTM_WARRIOR_H
#include "Player.h"

class Warrior : public Player{
public:
    /**C'tor for Warrior
     *
     * @param name the name of the player
     * creates new Warrior player with default values
     */
    explicit Warrior(const std::string& name) : Player(name) {};


    //Here we explicitly tell the compiler what defaults we wish to use
    Warrior& operator= (const Warrior&) =default;
    Warrior(const Warrior&) = default;
    ~Warrior() override = default;

    /*
     * @returns Warrior attack strength
     * the above calculated to be the sum of players level and force points
     * =(level+forcePoints*2)
      */
    int getAttackStrength() const override;

    /*
     * handles Barfight encounter for Warrior
     */
    void encounterBarfight() override;


    /*
     * print function
     */
    std::ostream& print(std::ostream& os) const override;
};



#endif //EX4_MTM_WARRIOR_H
