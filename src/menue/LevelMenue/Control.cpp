#include "Control.h"

//=====================================		CONSTRUCOR		==================================

Control::Control(sf::Vector2f size, sf::Vector2f position)
{
	m_control.setSize(size);
	m_control.setPosition(position);
}

//===============================  SET  =============================
void Control::setSize(const sf::Vector2f size)
{
	m_control.setSize(size);
}

void Control::setPosition(const sf::Vector2f position)
{
	m_control.setPosition(position);
}

void Control::setOrigin(const sf::Vector2f& origin)
{
	 m_control.setOrigin(origin);
}
//===============================  GET  =============================

State Control::getLastState() const
{
	return m_state;
}
sf::FloatRect Control::getGlobalBounds() const
{
	return m_control.getGlobalBounds();
}
sf::Vector2f Control::getSize() const
{
	return m_control.getSize();
}
sf::Vector2f Control::getPosition() const
{
	return m_control.getPosition();
}

sf::Vector2f Control::getOrigin() const
{
	return m_control.getOrigin();
}

State Control::getCurrentState(sf::Event& event)
{
	m_state = State::Normal;

	switch (event.type)
	{
	case sf::Event::MouseMoved:
	{
		if (m_control.getGlobalBounds().contains({ float(event.mouseMove.x), float(event.mouseMove.y) }))
			m_state = State::Moved;
	}break;
	case sf::Event::MouseButtonPressed:
	{
		if (m_control.getGlobalBounds().contains({ float(event.mouseButton.x), float(event.mouseButton.y) }))
			m_state = State::Pressed;
	}
	}	
	return m_state;
}



//===============================  HANDELING  =============================


void Control::eventHandled(sf::RenderWindow& window, sf::Event& event)
{
	m_control.setOrigin(m_control.getSize() / 2.0f);
	switch (event.type)
	{
	case sf::Event::MouseMoved:mouseMoved(window, event); break;
	case sf::Event::MouseButtonPressed:getCurrentState(event); break;
	}
}

void Control::mouseMoved(sf::RenderWindow& window, sf::Event& event)
{
	if (getCurrentState(event) == State::Moved)
	{
		if (m_control.getScale() == sf::Vector2f{ 1,1 })
			m_control.scale(SCALE);
		window.setMouseCursor(getCursorH());
		return;
	}
	m_control.setScale({ 1,1 });
}


//===============================  PRIVATE  =============================

sf::Cursor& Control::getCursorH()
{
	static sf::Cursor crcHand;
	crcHand.loadFromSystem(sf::Cursor::Hand);
	return crcHand;
}

void Control::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_control);
}