#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <list>
#include <vector>
#include <memory>
#include "Cards/Card.h"
#include "Players/Player.h"
#include "Leaderboard.h"

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

    ~Mtmchkin() = default;
    //we dont want to allow copying of the game.
    Mtmchkin(const Mtmchkin &mtmchkin) = delete;
    Mtmchkin &operator=(const Mtmchkin &mtmchkin) = delete;
    
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

    int m_teamSize;
    int m_numberOfRounds;

    std::vector<std::shared_ptr<Player>> m_players;

    Leaderboard m_leaderBoard; 

};



#endif /* MTMCHKIN_H_ */
