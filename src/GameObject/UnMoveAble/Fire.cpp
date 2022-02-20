#include "Fire.h"

//=====================================		CONSTRUCOR		==================================

Fire::Fire(sf::Vector2f position, sf::Vector2f size)
	:UnMoveAble(Resources::RscPic::getPicture(Resources::PictureName::Fire),position ,size)
{
	
}

//=====================================		HANDELING		==================================

void Fire::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

