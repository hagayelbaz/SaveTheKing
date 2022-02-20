#pragma once

#include "Level.h"
#include "menue.h"
#include "data.h"

//this class showing menue, sending speciffic selected level
class LevelManager
{
public:
	LevelManager(sf::RenderWindow& window);
	void show(sf::RenderWindow& window);
	Level& getLevel();

private:
	Level m_currentLevel;
	Menue m_menue;
};