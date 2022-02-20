#pragma once 

#include "selectLevel.h"
#include "Resources.h"
#include "Data.h"
#include <vector>
#include <fstream>

const float SPACE = 20.0f;
const sf::Vector2f DEFAULT_SIZE = { 60.0f,60.0f };
const sf::Vector2f MARGIN = { 10.0f,10.0f };
const sf::Color BACK_COLOR = sf::Color{ 199, 199, 199 ,100 };

class LevelMenue : public sf::Drawable
{
public:
	LevelMenue(sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 500.0f,500.0f });

	void setSize(const sf::Vector2f size);
	void setPosition(const sf::Vector2f position);
	void eventHandled(sf::RenderWindow& window, sf::Event& event);
	void mousePressed(sf::RenderWindow& window, sf::Event& event);

	int getsSelectedLevel();
	State getCurrentState(sf::Event& event);
	void refresh();

private:
	void setDefaultSetting();
	void add(bool lock, int levelNum = 0);
	void loadFromFile();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
	int m_selectedLevel = 1;
	std::vector<SelectLevel> m_levels;
	sf::Vector2f m_size;
	sf::Vector2f m_position;
	sf::RectangleShape m_border;
};