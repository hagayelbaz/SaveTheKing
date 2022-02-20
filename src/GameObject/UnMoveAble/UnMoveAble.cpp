#include "UnMoveAble.h"

//=====================================		CONSTRUCOR		==================================

UnMoveAble::UnMoveAble(const sf::Texture& picture, sf::Vector2f position, sf::Vector2f size)
	:GameObject(position , size)
{
	m_shape.setTexture(&picture);
}
