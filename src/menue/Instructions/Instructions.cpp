#include "Instructions.h"

Instructions::Instructions(sf::Vector2f position, sf::Vector2f size)
	:m_position(position),m_size(size)
{
	setDefaultSetting();
}

void Instructions::setSize(const sf::Vector2f size)
{
	m_size = size;
	setDefaultSetting();
}

void Instructions::setPosition(const sf::Vector2f position)
{
	m_position = position;
	setDefaultSetting();
}

void Instructions::eventHandled(sf::RenderWindow& window, sf::Event& event)
{

}

void Instructions::mousePressed(sf::RenderWindow& window, sf::Event& event)
{

}

const sf::Vector2f MARGIN = { 10.0f,10.0f };
const sf::Color BACK_COLOR = sf::Color{ 199, 199, 199 };

void Instructions::setDefaultSetting()
{
	m_position += MARGIN;
	m_size -= MARGIN * 4.0f;//fit size and pos

	m_border.setSize(m_size);
	m_border.setPosition(m_position);
	m_border.setFillColor(BACK_COLOR);
	m_border.setOutlineThickness(3);
	m_border.setOutlineColor(sf::Color::Black);

	m_border.setTexture(&Resources::RscPic::getPicture(Resources::PictureName::Instructions));
}

void Instructions::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_border);
}
