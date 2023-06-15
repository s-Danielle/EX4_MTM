//
// Created by Daniella on 15/06/2023.
//

#ifndef EX4_MTM_NINJA_H
#define EX4_MTM_NINJA_H

#include "Player.h"

class Ninja : public Player{
public:
    /**C'tor for Ninja
     *
     * @param name the name of the player
     * creates new Ninja player with default values
     */
    explicit Ninja(const string& name) : Player(name) {};

    Ninja& operator= (const Ninja&) =delete;
    Ninja(const Ninja&) = default;
    ~Ninja() override = default;
    //adds double the regular amount of coins
    void addCoins(int coinAmount) override;

};


#endif //EX4_MTM_NINJA_H
