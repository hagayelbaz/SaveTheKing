#pragma once

#include "collisionHandled.h"
#include <StatusLine.h>
#include "Data.h"


class GameManager
{
public:
	GameManager();
	void show(sf::RenderWindow& window);
	void setLevel(Level& level);

private:
	bool endLevel();
	void startGame(sf::RenderWindow& window);
	void fail();
	void win();
	void play(sf::RenderWindow& window);
	void nextPlayer();
	void resetLevel();
	void draw(sf::RenderWindow& window);

	int m_levelNumber = 1;
	sf::RectangleShape m_backGround;

	sf::Sound m_soundMain;//background sound
	sf::Sound m_soundReadygo;
	sf::Sound m_soundCountDown;

	Time m_timer;//time to show
	sf::Time m_deltaTime;
	sf::Clock m_clock;

	Level m_level;
	CollisionHandled m_collision;
	Player* m_currentPlayer = nullptr;

	std::map<PlayersName, std::shared_ptr<Player>> m_players;
	std::vector<std::shared_ptr<GameObject>> m_objects;
	std::vector<std::shared_ptr<GameObject>> m_dwarfs;
};

