
#include "StatusLineGui.h"

//=====================================		CONSTRUCOR		==================================

StatusLineGui::StatusLineGui(sf::Vector2f position, sf::Vector2f size)
{
	m_mainShape.setSize(size);
	m_mainShape.setPosition(position);
	m_mainShape.setFillColor(sf::Color::Transparent);

	m_text.setFont(m_font);
}

//=====================================		PUBLIC		==================================

void StatusLineGui::WriteLine(std::string line, sf::Color color)
{
	clear();//clear last string
	append(line, color);
}

void StatusLineGui::append(std::string str, sf::Color color)
{
	m_txt += str;
	m_text.setColor(color);
	m_text.setString(m_txt);

	//centered
	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_text.setPosition(
		sf::Vector2f(m_mainShape.getSize().x / 2.0f + m_mainShape.getPosition().x
			, m_mainShape.getSize().y / 2.0f + m_mainShape.getPosition().y));
}

void StatusLineGui::clear()
{
	m_txt.clear();
}

//=====================================		PRIVATE		==================================

void StatusLineGui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_mainShape);
    target.draw(m_text);
}
