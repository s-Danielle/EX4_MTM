#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <queue>
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
    const std::queue<std::shared_ptr<Card>> m_deck;
    int m_numberOfRounds;
    int m_teamSize;
    std::queue<std::shared_ptr<Player>> m_players;

};



#endif /* MTMCHKIN_H_ */
