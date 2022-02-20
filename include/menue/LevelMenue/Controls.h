#pragma once

#include <SFML/Graphics.hpp>
#include "Exit.h"
#include "Play.h"
#include "Next.h"

enum class Clicked { Exit, Play, Next, None };

//list 3 controls - exit , play , next (instructions / levels)
class Controls : public sf::Drawable
{
public:
	Controls(sf::Vector2f size = { 0.0f,0.0f }, sf::Vector2f position = { 0.0f,0.0f });

	void setDefaultSetting();
	void setBaseSize(sf::Vector2f size);
	void setBasePosition(sf::Vector2f position);

	void eventHandled(sf::RenderWindow& window, sf::Event& event);
	bool isMouseHovered(sf::Event& event);

	sf::Vector2f getSize() const;
	sf::Vector2f getPosition() const;

	//witch button clicked
	Clicked getClickedControl(sf::Event& event);

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


	sf::Vector2f m_baseSize;
	sf::Vector2f m_basePosition;

	Exit m_exit;
	Play m_play;
	Next m_next;
};