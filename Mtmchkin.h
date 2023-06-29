#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <list>
#include <vector>
#include "Card.h"

class Mtmchkin{

public:

    static const int MIN_DECK_SIZE = 5;
    static const int MAX_PLAYERS = 6;
    static const int MIN_PLAYERS = 2;
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    const std::vector<std::unique_ptr<const Card>> m_deck;
    std::vector<std::unique_ptr<const Card>>::const_iterator m_currentCard;

    std::vector<std::shared_ptr<Player>> m_players;

    std::list<std::shared_ptr<const Player>> m_leaderBoard; 
    // i want to update it every round. holds pointers to players in m_players, in the leader board order. 
    //the players should not be changed in the list, only the order of the pointers, so i used const pointers.

    int m_numberOfRounds;
    int m_teamSize;

    const std::shared_ptr<const Card> getCurrentCard() const;
};



#endif /* MTMCHKIN_H_ */
