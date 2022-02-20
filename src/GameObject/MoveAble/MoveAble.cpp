#include "MoveAble.h"

//=====================================		PUBLIC		==================================

void MoveAble::setSpeed(const float speed)
{
	m_speed = speed;
}

float MoveAble::getSpeed() const
{
	return m_speed;
}

void MoveAble::setPosition(const sf::Vector2f position)
{
	GameObject::setPosition(position);
}

//=====================================		PROTECTED		==================================

void MoveAble::stepBack()
{
	m_shape.setPosition(m_lastLocation);
}
