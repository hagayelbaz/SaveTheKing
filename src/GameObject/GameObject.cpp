#include "GameObject.h"


//=====================================		CONSTRUCOR		==================================

GameObject::GameObject(sf::Vector2f position, sf::Vector2f size)
{
	m_shape.setPosition(position);
	m_shape.setSize(size);
}

//=====================================		PUBLIC		==================================

void GameObject::setPosition(const sf::Vector2f position)
{
	m_shape.setPosition(position);
}

void GameObject::setSize(const sf::Vector2f size)
{
	m_shape.setSize(size);
}

sf::Vector2f GameObject::getPosition() const
{
	return m_shape.getPosition();
}

sf::FloatRect GameObject::getGlobalBounds() const
{
	return m_shape.getGlobalBounds();
}
sf::Vector2f GameObject::getSize() const
{
	return m_shape.getSize();
}
void GameObject::deleteItem()
{
	m_deleted = true;
}
bool GameObject::isDeleted() const
{
	return m_deleted;
}
void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_shape, states);
}
