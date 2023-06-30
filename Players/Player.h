//
// Created by Daniella on 13/06/2023.
//
#ifndef EX4_MTM_PLAYER_H
#define EX4_MTM_PLAYER_H

#include <string>




class Player {
public:
    //const Values:
    static const int DEFAULT_MAX_HP =100;
    static const int DEFAULT_COINS =10;
    static const int DEFAULT_FORCE_POINTS=5;
    static const int MAX_NAME_LEN=15;
    static const int MAX_LEVEL=10;
    /*
     * Increases player level by 1 up to level 10
     * above level 10 does nothing
     */
    void levelUp();

    /*
  ==============you've got mail!================
    i added this method.
    zohar <3.

     * @returns true if player is a winner and false if not
     * player is a winner if he is level 10
     */
    bool isWinner() const;

    /*returns true if the player is still in the game*/
    bool isPlaying() const;

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
     *@returns player name
     */
    std::string getName() const;

    /*
     * returns player coins
     */
    int getCoins() const;

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
     * default printing function using utilities.h
     */
    virtual std::ostream& print(std::ostream& os) const =0;

    /*
     * overloading >> operator
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    /*
    * Here we are explicitly telling the compiler to use the default/delete methods
    */
    Player& operator = (const Player&) = default;
    Player(const Player&) = default;
    virtual ~Player() = default;

protected:
    /**
     * C'tor of Player class
     *
     * @param name - the name of the player throws exception if name is invalid
     * creates new player with default values
     */
    explicit Player(const std::string& name);

    std::string m_name; // consists only of english letters, max 15 chars
    int m_level; //range 1-10
    int m_force; // non-negative
    int m_currentHealth; // range 0- maxHP
    int m_coins; //non-negative

};

/**
  *Factory-like function
  * @param playerType desired class, throws an exception if invalid
  * @param playerName throws an exception if invalid
  * @return a pointer to a new player of the correct type on the heap
  * caller is responsible to delete data
  */
Player* createNewPlayer(const std::string& job, const std::string &playerName);

#endif //EX4_MTM_PLAYER_H
