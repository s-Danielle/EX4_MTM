//
// Created by Daniella on 13/06/2023.
//

#include "Player.h"
#include "../utilities.h"
#include "Ninja.h"
#include "Warrior.h"
#include "Healer.h"

enum PlayerType PlayerType(const string& type){
    //TODO: the whole enum thing is a bit weird. why not just use a string?
    if(type=="Ninja"){
        return PlayerType::Ninja;
    }
    if(type=="Healer"){
        return PlayerType::Healer;
    }
    if(type=="Warrior"){
        return PlayerType::Warrior;
    }
    throw std::exception();//TODO: throw exception, maybe create a new one for this
}

string Player::getName() const {
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


Player *Player::CreateNewPlayer(enum PlayerType playerType, string &playerName) {
    //kinda cluncky tbh. i really liked the map idea. either way, this is a factory method.
    //TODO: maybe make it its own class/header?
    //why not just use a string?, why not just 'return new Warrior(playerName);'?
    Player* newPlayer;
    switch (playerType) {
        case PlayerType::Warrior :{
            newPlayer= new Warrior(playerName);
            return newPlayer;
        }
        case PlayerType::Ninja:{
            newPlayer= new Ninja(playerName);
            return newPlayer;
        }
        case PlayerType::Healer:{
            newPlayer= new Healer(playerName);
            return newPlayer;
        }
        default: {
            throw std::exception(); //TODO specify exception
        }
    }
}


std::ostream& operator<<(std::ostream& os,const Player& player) {
    player.print(os);
    return os;
}