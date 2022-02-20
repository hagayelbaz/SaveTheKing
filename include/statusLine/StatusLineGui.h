#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "ResourcesPicture.h"
#include "ResourcesFont.h"

class StatusLineGui : public sf::Drawable
{
public:
	StatusLineGui(sf::Vector2f position = { 0.0f, 0.0f}, sf::Vector2f size = {40.0f, 40.0f});
    void WriteLine(std::string line, sf::Color color = sf::Color::White);
	void append(std::string str, sf::Color color = sf::Color::White);
	void clear();
private: 
	sf::RectangleShape m_mainShape;
	sf::Font& m_font = Resources::RscFont::getFont(Resources::FontName::Special);
	sf::Text m_text;
	std::string m_txt;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};