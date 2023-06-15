//
// Created by Daniella on 15/06/2023.
//

#ifndef EX4_MTM_HEALER_H
#define EX4_MTM_HEALER_H
#include "Player.h"

class Healer : public Player{
public:
    /**C'tor for Healer
     *
     * @param name the name of the player
     * creates new Healer player with default values
     */
    explicit Healer(const string& name) : Player(name) {};

    //Here we explicitly tell the compiler what defaults we wish to use
    Healer& operator= (const Healer&) =delete;
    Healer(const Healer&) = default;
    ~Healer() override = default;
    /*
     * heals twice the amount given compared to other classes
     */
    void heal(int points) override;
};


#endif //EX4_MTM_HEALER_H
