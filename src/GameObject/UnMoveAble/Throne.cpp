#include "Throne.h"

//=====================================		CONSTRUCOR		==================================

Throne::Throne(sf::Vector2f position, sf::Vector2f size)
	:UnMoveAble(Resources::RscPic::getPicture(Resources::PictureName::Throne), position, size)
{

}

//=====================================		HANDELING		==================================

void Throne::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}
