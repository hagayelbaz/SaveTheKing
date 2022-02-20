#pragma once

#include <SFML/Graphics.hpp>
#include "Level.h"
#include "GameManager.h"
#include "LevelManager.h"

class Controler {
public:
	Controler();
	void run();
private:	
		
	GameManager m_gameManager;
	sf::RenderWindow m_window;
	Level m_currentLevel;	
	LevelManager m_levelManager;
};