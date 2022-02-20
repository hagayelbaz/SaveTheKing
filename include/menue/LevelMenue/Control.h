#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "ResourcesPicture.h"

const sf::Vector2f SCALE = { 1.2,1.2 };//on hover scale
enum class State { Normal, Pressed, Moved };


class Control : public sf::Drawable
{
public:

	Control(sf::Vector2f size = { 0.0f,0.0f }, sf::Vector2f position = { 0.0f,0.0f });
	
	State getLastState() const;
	sf::FloatRect getGlobalBounds() const;
	sf::Vector2f getSize() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getOrigin() const;
	

	State getCurrentState(sf::Event& event);//event needed for update

	virtual void setSize(const sf::Vector2f size);
	virtual void setPosition(const sf::Vector2f position);
	virtual void eventHandled(sf::RenderWindow& window, sf::Event& event);
	virtual void mouseMoved(sf::RenderWindow& window, sf::Event& event);
	virtual void setOrigin(const sf::Vector2f &origin);

protected:
	sf::Cursor& getCursorH();//hand cursor
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::RectangleShape m_control;

private:
	virtual void setDefaultSetting() = 0;	
	State m_state;
};