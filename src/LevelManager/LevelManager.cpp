#include "LevelManager.h"


//=====================================		CONSTRUCOR		==================================

LevelManager::LevelManager(sf::RenderWindow& window)
	:m_menue(window)
{
	m_currentLevel = Level(1);
}
//=====================================		PUBLIC		==================================

void LevelManager::show(sf::RenderWindow& window)
{
	//load from file if was changes
	m_menue.refresh();
	m_menue.show(window);
	//move to selected level
	m_currentLevel.moveTo(m_menue.getSelectedLevel());
}

Level& LevelManager::getLevel()
{
	return m_currentLevel;
}
