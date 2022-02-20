#include "Key.h"

//=====================================		CONSTRUCOR		==================================

Key::Key(sf::Vector2f position, sf::Vector2f size)
	:UnMoveAble(Resources::RscPic::getPicture(Resources::PictureName::Key), position ,size)
{

}

//=====================================		PUBLIC		==================================

void Key::takeKey()
{
	this->deleteItem();
}

//=====================================		HANDELING		==================================

void Key::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}
