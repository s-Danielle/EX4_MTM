#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "Players/Player.h"
#include <list>
#include <vector>
#include <memory>
class Leaderboard{
public:
	/*constructor*/
	Leaderboard(std::vector<std::shared_ptr<Player>>& playerList);


	~Leaderboard()=default;
	Leaderboard(const Leaderboard& leaderboard)=default;
	Leaderboard& operator=(const Leaderboard& leaderboard)=default;
	/*gets a player (who just won\lost) and updates its place in the leaderboard accordingly*/
	void update(std::shared_ptr<Player>& player);
	/*prints the leaderboards*/
	void print() const;
	

private:
	std::vector<std::shared_ptr< Player>> m_allPlayers;
	std::vector<std::shared_ptr< Player>> m_winners; //winners vector
	std::vector<std::shared_ptr<Player>> m_losers; //losers vector

	std::vector<std::shared_ptr<Player>> getLeaderBoard() const;
};
#endif //LEADERBOARD_H