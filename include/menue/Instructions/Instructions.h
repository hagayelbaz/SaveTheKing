#pragma once 

#include "Resources.h"
#include "ResourcesPicture.h"
#include "Data.h"



class Instructions : public sf::Drawable
{
public:
	Instructions(sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 500.0f,500.0f });

	void setSize(const sf::Vector2f size);
	void setPosition(const sf::Vector2f position);
	void eventHandled(sf::RenderWindow& window, sf::Event& event);
	virtual void mousePressed(sf::RenderWindow& window, sf::Event& event);

private:
	virtual void setDefaultSetting();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::Vector2f m_size;
	sf::Vector2f m_position;
	sf::RectangleShape m_border;
};