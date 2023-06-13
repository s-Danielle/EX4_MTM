//
// Created by Daniella on 13/06/2023.
//
//TODO
//implement player class and 3 subtypes-Ninja,Warrior and Healer

#ifndef EX4_MTM_PLAYER_H
#define EX4_MTM_PLAYER_H

#include <string>
using std::string;

#define DEFAULT_MAX_HP 100
#define DEFAULT_COINS 10
#define DEFAULT_FORCE_POINTS 5


class Player {
public:
    /**
     * C'tor of Player class
     *
     * @param name  - the name of the player -//TODO handle invalid input
     * creates new player with default values
     */
    explicit Player(const string& name);


    /*
     * Prints player info USING THE utilities.h function
     */
    virtual void printInfo() const; //TODO implement as operator >>

    /*
     * Increases player level by 1 up to level 10
     * above level 10 does nothing
     */
    void levelUp();

    /*
     * @returns player level
     */
    int getLevel() const;

    /*
     * Increases player force points by the amount specified
     */
    void buff(int forcePoints);

    /**
     * heals the player by amount of given points up to max HP
     * @param healthPoints - points to add
     */
    virtual void heal(int healthPoints);

    /**
     * damages the player by specified amount
     * if amount is smaller than zero nothing will be done
     * if the amount is greater than current HP - health points will be reduced to 0
     * @param healthPoints - points to reduce
     */
    void damage(int healthPoints);

    /*
     * @returns true if player is knocked out ie reached 0 HP and false if not
     */
    bool isKnockedOut() const;

    /**
     * adds coins to player
     * @param coinAmount - coins to add
     */
    virtual void addCoins(int coinAmount);

    /**
     * payment function-check if affordable and handles payment
     * reduces player coins upon successful payment
     * @param price - the amount of coins wanted to reduce
     * @return true for successful payment ie player has enough coins and false if not
     */
    bool pay(int price);


    /*
     * @returns player attack strength
     * the above calculated to be the sum of players level and force points
     * =(level+forcePoints)
     */
    virtual int getAttackStrength() const;


    /*
    * Here we are explicitly telling the compiler to use the default/delete methods
    */
    Player& operator = (const Player&) = delete; // ??
    Player(const Player&) = default;
    virtual ~Player() = default;

private:

    string m_name; // consists only of english letters, max 15 chars
    int m_level; //range 1-10
    int m_force; // non-negative
    int m_currentHealth; // range 0- maxHP
    int m_coins; //non-negative

};

class Ninja : Player{
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


class Healer : Player{
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

class Warrior : Player{
public:
    /**C'tor for Warrior
     *
     * @param name the name of the player
     * creates new Warrior player with default values
     */
    explicit Warrior(const string& name) : Player(name) {};
    //Here we explicitly tell the compiler what defaults we wish to use
    Warrior& operator= (const Warrior&) =delete;
    Warrior(const Warrior&) = default;
    ~Warrior() override = default;

    /*
     * @returns Warrior attack strength
     * the above calculated to be the sum of players level and force points
     * =(level+forcePoints*2)
      */
    int getAttackStrength() const override;

};


#endif //EX4_MTM_PLAYER_H
