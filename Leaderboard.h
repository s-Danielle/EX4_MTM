#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "Player.h"
#include <vector>
#include <memory>
class Leaderboard{
public:
	Leaderboard();
	~Leaderboard();
	Leaderboard(const Leaderboard& leaderboard);
	Leaderboard& operator=(const Leaderboard& leaderboard)=delete;
	/*gets a player (who just won\lost) and updates its place in the leaderboard accordingly*/
	void update(const Player& player);

private:
	std::vector<std::shared_ptr<const Player>> m_currentlyPlaying;
	std::vector<std::shared_ptr<const Player>> m_winners; //winners vector
	std::vector<std::shared_ptr<const Player>> m_losers; //losers vector

#endif //LEADERBOARD_H