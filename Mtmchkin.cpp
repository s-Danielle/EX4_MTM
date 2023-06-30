#include "Mtmchkin.h"
#include <fstream>
#include <sstream>
#include <cassert>
#include "Exception.h"
#include "utilities.h"
#include "StringUtils.h"

using std::shared_ptr;
using std::unique_ptr;
using std::vector;

static vector<unique_ptr<const Card>> createDeck(const std::string &fileName);
static int getTeamSize();
static vector<shared_ptr<Player>> createPlayerList(int teamSize);
static shared_ptr<Player> createPlayer();


/**@param fileName: text file with card list.
 * initializes a game of Mtmchkin.(constructor)
 */
Mtmchkin::Mtmchkin(const std::string &fileName) : m_deck(createDeck(fileName)),
												  m_currentCard(m_deck.begin()),
												   m_teamSize(getTeamSize()),
												   m_numberOfRounds(0),
													m_players(createPlayerList(m_teamSize)),
												    m_leaderBoard(m_players)
{
}

void Mtmchkin::playRound()
{
	printRoundStartMessage(m_numberOfRounds);
	// for each player that didn't die or win
	for(shared_ptr<Player> currentPlayer : m_players){
		if(!currentPlayer->isPlaying()){
			continue;
		}
		// play card
		(*m_currentCard)->applyEncounter(*currentPlayer);	//critical point
		// check if game ended
		//update cards iterator
		if(++m_currentCard==m_deck.end()){
			m_currentCard=m_deck.begin();
		}
		//update leader board if needed
		if(!currentPlayer->isPlaying()){
			m_leaderBoard.update(currentPlayer);
		}
	}
	m_numberOfRounds++;
}

void Mtmchkin::printLeaderBoard() const
{

}
bool Mtmchkin::isGameOver() const
{
	for(shared_ptr<Player> currentPlayer : m_players){
		if(currentPlayer->isPlaying()){
			return false;
		}
	}
	return true;
} 

int Mtmchkin::getNumberOfRounds() const
{
	return m_numberOfRounds;
}


/**
 * ==================================================================
 * ========================Helper Functions==========================
 * ==================================================================
*/


/**@param fileName: file path.
 * @return: a queue of unique_ptr to cards.
 * creates a deck from a file.
 * throws DeckFileNotFound if the file does not exist.
 * throws DeckFileFormatError if the file is not in the correct format.
 * throws DeckFileInvalidSize if the deck is too small.
 */
static vector<unique_ptr<const Card>> createDeck(const std::string &fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		throw DeckFileNotFound();
	}
	vector<unique_ptr<const Card>> deck;
	std::string line;
	int lineNum = 0;
	while (std::getline(file, line))
	{
		line = strip(line);
		lineNum++;
		if (line.length() == 0)
		{
			/*if we encountered an empty line, it means either were done, or that there was an error.*/
			while(std::getline(file, line)){
				if(strip(line).length()!=0){
					throw DeckFileFormatError(lineNum);
				}
			}
			break;
		}

		if(countWords(line)!=1){
			throw DeckFileFormatError(lineNum);
		}

		Card* currentCard = nullptr;
		try{
			currentCard = createNewCard(line);
		}
		catch(InvalidInput& e){
			throw DeckFileFormatError(lineNum);
		}


		deck.emplace_back(currentCard); // i think i can only do this in c++11, so i hope they will compile it like they said.
									   //make_unique is c++14 and above.
	}
	if (lineNum <= Mtmchkin::MIN_DECK_SIZE)
	{
		throw DeckFileInvalidSize();
		// make sure to not leak memory.
	}
	printStartGameMessage();
	return deck;	//TODO: make sure it does not cause problems with the unique_ptr
}
/**@return: number from standard input.
 * checks if the input is valid, if not, prints an error message and asks for input again.
 * the number is in [MIN_PLAYERS, MAX_PLAYERS] range.
 */
static int getTeamSize()
{
	
	std::string line;
	int teamSize;
	bool successfulInput = false;
	while (!successfulInput)
	{
		try
		{
			printEnterTeamSizeMessage();
			std::getline(std::cin, line);
			teamSize = std::stoi(line);
			successfulInput = true;
		}
		catch (std::logic_error &e)
		{
			printInvalidTeamSize();
			successfulInput = false;
			continue;
		}
		if (countWords(line)!= 1 ||teamSize > Mtmchkin::MAX_PLAYERS || teamSize < Mtmchkin::MIN_PLAYERS)
		{
			printInvalidTeamSize();
			successfulInput = false;
			continue;
		}
	}
	return teamSize;
}

/**@param teamSize: number of players in the game.
 * @return: a vector of shared_ptr to players.
 * creates a vector of players from standard input.
 */
static vector<shared_ptr<Player>> createPlayerList(int teamSize)
{
	printEnterTeamSizeMessage();
	vector<shared_ptr<Player>> players;
	int playersCreated = 0;
	while(playersCreated<teamSize){
		try{
			players.push_back(createPlayer());
		}
		catch(InvalidPlayerName& e){
			printInvalidName();
			continue;
		}
		catch(InvalidPlayerClass& e){
			printInvalidClass();
			continue;
		}
		catch(InvalidInput& e){
			printInvalidInput();
			continue;
		}
		playersCreated++;
	}
	return players;
}

/**@return: a shared_ptr to a player.
 * creates a player from standard input, using the factory method createNewPlayer.
 */
static shared_ptr<Player> createPlayer(){ //TODO: bad name
	string input;
	printInsertPlayerMessage();
	std::getline(std::cin, input);
	if(countWords(input)!=2){
		throw InvalidInput();
	}

	shared_ptr<Player> player(createNewPlayer(extractNthWord(input, 1), extractNthWord(input, 2)));
	//i dont like using having 'magic numbers' in my code, but seems stupid to create a const for 1 and 2.
	return player;
}