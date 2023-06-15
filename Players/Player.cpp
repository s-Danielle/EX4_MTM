//
// Created by Daniella on 13/06/2023.
//

#include "Player.h"


#include "utilities.h"
#include "Player.h"


Player::Player(const string& name) :
        m_name(name), m_level(1),
        m_force(DEFAULT_FORCE_POINTS),
        m_currentHealth(DEFAULT_MAX_HP),
        m_coins(DEFAULT_COINS){};

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

int Player::getAttackStrength() const {
    return m_force+m_level;
}




