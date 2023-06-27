#include "Mtmchkin.h"
#include <memory>
#include <fstream>
#include "Exception.h"
#include "utilities.h"
using std::shared_ptr;
using std::vector;

/**@param fileName: text file with card list.
 * initializes a game of Mtmchkin.(constructor)
 */
Mtmchkin::Mtmchkin(const std::string &fileName) : m_deck(createDeck(fileName)),
												  m_currentCard(m_deck.begin()),
												   m_players(), m_leaderBoard(),
												    m_numberOfRounds(0)
{
	printStartGameMessage();
	printEnterTeamSizeMessage();
	m_teamSize = getTeamSize();
	m_players = createPlayerList(m_teamSize);
	m_currentPlayer = m_players.begin();
	m_leaderBoard.assign(m_players.begin(), m_players.end());
}

void Mtmchkin::playRound()
{
	printRoundStartMessage(m_numberOfRounds);
	// for each player how didn't die or win
	// print start turn message
	// play card
	// check if game ended
}

/**@param fileName: file path.
 * @return: a queue of unique_ptr to cards.
 * creates a deck from a file.
 * throws DeckFileNotFound if the file does not exist.
 * throws DeckFileFormatError if the file is not in the correct format.
 * throws DeckFileInvalidSize if the deck is too small.
 */
static vector<shared_ptr<Card>> createDeck(const std::string &fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		throw DeckFileNotFound();
	}
	vector<shared_ptr<Card>> deck;
	std::string line;
	int lineNum = 0;
	while (std::getline(file, line))
	{
		if (line.length() == 0)
		{
			// empty line;
		}
		lineNum++;
		Card *currentCard = createNewCard(line); // TODO:call factory method, fix this mess, its in a constructor
		// handle exceptions
		deck.push_back(shared_ptr<Card>(currentCard)); // maybe collapse this line into the previous one
	}
	// TODO: check for empty lines/lines with only spaces/empty deck
	if (lineNum <= Mtmchkin::MIN_DECK_SIZE)
	{
		throw DeckFileInvalidSize();
		// make sure to not leak memory.
	}
	return deck;
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
		if (teamSize > Mtmchkin::MAX_PLAYERS || teamSize < Mtmchkin::MIN_PLAYERS)
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
 * creates a list of players from standard input.
 */
static vector<shared_ptr<Player>> createPlayerList(int teamSize)
{
	vector<shared_ptr<Player>> players;
	
}