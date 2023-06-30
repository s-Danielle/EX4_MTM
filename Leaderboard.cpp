#include "Leaderboard.h"
#include "utilities.h"


Leaderboard::Leaderboard(std::vector<std::shared_ptr<Player>> &playerList) : m_allPlayers(), m_winners(), m_losers()
{
	m_allPlayers.assign(playerList.begin(), playerList.end());
	m_winners.clear();
	m_losers.clear();
}

void Leaderboard::update(std::shared_ptr<Player> &player)
{
	if(player->isWinner()){
		m_winners.push_back(player);
	}
	else if(player->isKnockedOut()){
		m_losers.push_back(player);
	}
	else{
		return;
	}
}

void Leaderboard::print() const
{
	printLeaderBoardStartMessage();
	int ranking = 1;
	for(auto currentPlayer : this->getLeaderBoard()){
		printPlayerLeaderBoard(ranking, *currentPlayer);
		ranking++;
	}
}

std::vector<std::shared_ptr<Player>> Leaderboard::getLeaderBoard() const
{
	std::vector<std::shared_ptr<Player>> leaderBoard;
	leaderBoard.assign(m_winners.begin(), m_winners.end());
	for(auto currentPlayer : m_allPlayers){
		if(currentPlayer->isPlaying()){
			leaderBoard.push_back(currentPlayer);
		}
	}
	for(auto it=m_losers.rbegin(); it!=m_losers.rend(); ++it){
		leaderBoard.push_back(*it);
	}
	return leaderBoard;
}





