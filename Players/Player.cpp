//
// Created by Daniella on 13/06/2023.
//

#include "Player.h"
#include "../utilities.h"
#include "Ninja.h"
#include "Warrior.h"
#include "Healer.h"

bool nameCheck(const std::string& name){
    bool check =true;
    for (char i : name) {
        check = check && isalpha(i);
    }
    check = check && name.length()<=15;
    //==========you've got mail!================
    // '15' should be a static const member variable.
    //  zohar <3. 
    return check;
}

Player::Player(const std::string &name)  :
        m_name(name), m_level(1),
        m_force(DEFAULT_FORCE_POINTS),
        m_currentHealth(DEFAULT_MAX_HP),
        m_coins(DEFAULT_COINS){
    if(!nameCheck(name)){
        throw std::exception();//TODO: specify
            //==========you've got mail!================
            // throw "InvalidPlayerName".
            //  zohar <3. 
    }
}


std::string Player::getName() const {
    return m_name;
}

int Player::getCoins() const {
    return m_coins;
}

void Player::levelUp() {
    if(m_level<10){
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int forcePoints) {
    m_force+=forcePoints;
}

void Player::heal(int healthPoints) {
    m_currentHealth+=healthPoints;
    if(m_currentHealth>DEFAULT_MAX_HP){
        m_currentHealth=DEFAULT_MAX_HP;
    }
}

void Player::damage(int healthPoints) {
    m_currentHealth-=healthPoints;
    if(m_currentHealth<0){
        m_currentHealth=0;
    }
}

bool Player::isKnockedOut() const {
    return m_currentHealth==0;
}

void Player::addCoins(int coinAmount) {
    m_coins+=coinAmount;
}

bool Player::pay(int price) {
    if(price>m_coins){
        return false;
    }
    m_coins-=price;
    return true;
}

void Player::encounterBarFight() {
    printBarfightMessage(false);
    damage(10);
}

void Player::encounterMana() {
    printManaMessage(false);
    //do nothing
}

void Player::encounterWell() {
    printWellMessage(false);
    damage(10);
}


int Player::getAttackStrength() const {
    return m_force+m_level;
}


Player* CreateNewPlayer(const std::string& job, const std::string &playerName) {
    if (job=="Ninja"){
        return new Ninja(playerName);
    }
    if(job=="Healer") {
        return new Healer(playerName);
    }
    if(job=="Warrior") {
        return new Warrior(playerName);
    }
    else{
        throw std::exception(); //TODO: specify exception

        //==========you've got mail!================
        // throw "InvalidPlayerClass".
        //  zohar <3.
    }
}


std::ostream& operator<<(std::ostream& os,const Player& player) {
    player.print(os);
    return os;
}