#include "Controls.h"

const float SPACE = 150.0f;
//9% from base size
const float PERCENT = 9.0f;

//=====================================		CONSTRUCOR		==================================

Controls::Controls(sf::Vector2f size, sf::Vector2f position)
	:m_baseSize(size), m_basePosition(position)
{
	setDefaultSetting();
}

//=====================================		SET		==================================

void Controls::setBaseSize(sf::Vector2f size)
{
	m_baseSize = size;
	setDefaultSetting();
}

void Controls::setBasePosition(sf::Vector2f position)
{
	m_basePosition = position;
	setDefaultSetting();
}
//=====================================		GET		==================================

sf::Vector2f Controls::getSize() const
{
	float xSize = m_next.getPosition().x - m_exit.getPosition().x + m_next.getSize().x;
	float ySize = m_exit.getSize().y * 1.5;//because origin
	return sf::Vector2f(xSize, ySize);
}

sf::Vector2f Controls::getPosition() const
{
	return m_exit.getPosition();
}

Clicked Controls::getClickedControl(sf::Event& event)
{
	if (m_play.getCurrentState(event) == State::Pressed)
		return Clicked::Play;
	if (m_next.getCurrentState(event) == State::Pressed)
		return Clicked::Next;
	if (m_exit.getCurrentState(event) == State::Pressed)
		return Clicked::Exit;
	return Clicked::None;
}

//=====================================		PUBLIC		==================================

bool Controls::isMouseHovered(sf::Event& event)
{
	if ((m_exit.getCurrentState(event) == State::Moved) ||
		(m_next.getCurrentState(event) == State::Moved) ||
		(m_play.getCurrentState(event) == State::Moved))
		return true;
	return false;
}

void Controls::setDefaultSetting()
{
	
	auto btnSize = m_baseSize / PERCENT;
	m_exit.setSize(btnSize);
	m_play.setSize(btnSize);
	m_next.setSize(btnSize);

	m_exit.setOrigin(btnSize / 2.0f);
	m_play.setOrigin(btnSize / 2.0f);
	m_next.setOrigin(btnSize / 2.0f);


	float yPosition = m_basePosition.y + m_baseSize.y - btnSize.y;
	float sizeAllItem = 3 * (btnSize.x + SPACE) - SPACE;//-space , spaces are 2
	float xPosFirst = (m_baseSize.x - sizeAllItem) / 2;//centered

	m_exit.setPosition({ m_basePosition.x +  xPosFirst + btnSize.x / 2.0f ,yPosition });
	m_play.setPosition({ m_exit.getPosition().x + btnSize.x + SPACE , yPosition });
	m_next.setPosition({ m_play.getPosition().x + btnSize.x + SPACE , yPosition });
}

//=====================================		HANDELING		==================================

void Controls::eventHandled(sf::RenderWindow& window, sf::Event& event)
{
	m_exit.eventHandled(window, event);
	m_play.eventHandled(window, event);
	m_next.eventHandled(window, event);
}

//=====================================		PRIVATE		==================================

void Controls::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_exit);
	target.draw(m_play);
	target.draw(m_next);
}
