//
// Created by Daniella on 13/06/2023.
//
//TODO
//implement player class and 3 subtypes-Ninja,Warrior and Healer

#ifndef EX4_MTM_PLAYER_H
#define EX4_MTM_PLAYER_H

#include <string>
using std::string;

#define DEFAULT_MAX_HP 100  //TODO: this is not how we define constants in c++!!!!
#define DEFAULT_COINS 10
#define DEFAULT_FORCE_POINTS 5

/**
 * Player Type
 */
enum class PlayerType {Ninja, Warrior, Healer}; //why enum class???

/**
 * converts string to PlayerType
 * @param strType string that contains the requested class
 * @return Player type variable
 * throws invalid type if no strings match
 */
enum PlayerType PlayerType(const string& type); //TODO: why not just use a string?


class Player {
public:

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

    /**
     *
     * @param playerType use PlayerType(string type) to convert string to enum- safe use as it throws an exception
     * @param playerName expected to be valid - up to caller to check the string to match requirements!
     * @return a pointer to a new player of the correct type on the heap
     * caller is responsible to delete data
     */
    static Player* CreateNewPlayer(enum PlayerType playerType, string &playerName);


    /*
     * @returns player attack strength
     * the above calculated to be the sum of players level and force points
     * =(level+forcePoints)
     */
    virtual int getAttackStrength() const;

    /*
     *@returns player name
     */
    string getName() const;

    /*
     * returns player coins
     */
    int getCoins() const;
    /*
     * prints player details using utilities.h
     */

    /*
     * Player falls into Well
     */
    virtual void encounterWell();

    /*
    * Player gets into bar fight
    */
    virtual void encounterBarFight();

    /*
   * Player falls into Well
   */
    virtual void encounterMana();


    /*
     * default printing function
     */
    virtual std::ostream& print(std::ostream& os) const =0;

    /*
     * overloading >> operator
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    /*
    * Here we are explicitly telling the compiler to use the default/delete methods
    */
    Player& operator = (const Player&) = default; // ?? wtf is this
    Player(const Player&) = default;
    virtual ~Player() = default;

protected:
    /**
     * C'tor of Player class
     *
     * @param name  - the name of the player -//TODO handle invalid input
     * creates new player with default values
     */
    explicit Player(const string& name) :
            m_name(name), m_level(1),
            m_force(DEFAULT_FORCE_POINTS),
            m_currentHealth(DEFAULT_MAX_HP),
            m_coins(DEFAULT_COINS){};

    string m_name; // consists only of english letters, max 15 chars
    int m_level; //range 1-10
    int m_force; // non-negative
    int m_currentHealth; // range 0- maxHP
    int m_coins; //non-negative

};


#endif //EX4_MTM_PLAYER_H
