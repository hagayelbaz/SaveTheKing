#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "ResourcesFont.h"
#include "Control.h"
#include <fstream>      


class SelectLevel : public Control
{
public:
	SelectLevel(sf::Vector2f baseSize = { 0.0f,0.0f }, sf::Vector2f basePosition = { 0.0f,0.0f });

	virtual void setSize(const sf::Vector2f size) override;
	virtual void setPosition(const sf::Vector2f position) override;
	virtual void eventHandled(sf::RenderWindow& window, sf::Event& event) override;
	virtual void mousePressed(sf::RenderWindow& window, sf::Event& event);

	bool isLock() const;
	void lock(bool lock, int levelNumber);
	int getLevelNumber();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setDefaultSetting();

	int m_selectedLevel = 0;// = 0 if not selected
	bool m_lock = true;
	sf::Text m_text;
};