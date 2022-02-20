#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Controls.h"
#include "LevelMenue.h"
#include "Level.h"
#include "Instructions.h"
#include <fstream>      



class Menue : public sf::Drawable
{
public:
	Menue(sf::RenderWindow& window);
	void show(sf::RenderWindow& window);


	void eventHandledLevels(sf::RenderWindow& window, sf::Event& event, bool &endLevel);
	void eventHandledInstructions(sf::RenderWindow& window, sf::Event& event, bool& endLevel);
	void eventHandled(sf::RenderWindow& window, sf::Event& event, bool& endLevel);

	int getSelectedLevel();
	void refresh();

private:
	enum class MenueState{Levels, Instructions};

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setDefaultSetting(sf::RenderWindow& window);
	void replaceCursor(sf::RenderWindow& window, sf::Event& event);

	const sf::Vector2f MARGIN = { 100.0f,100.0f };
	const sf::Color BORDER_COLOR = sf::Color{ 22, 1, 39 };
	const int BORDER_SIZE = 10;

	sf::Sound m_sound;
	sf::RectangleShape m_borderShape;
	sf::RectangleShape m_backGround;
	sf::Cursor m_arrowCursor;

	Controls m_controls;//play next exit
	LevelMenue m_levels;//level buttons
	Instructions m_instructions;
	MenueState m_state = MenueState::Levels;

};