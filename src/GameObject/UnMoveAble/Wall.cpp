#include "Wall.h"

//=====================================		CONSTRUCOR		==================================

Wall::Wall(sf::Vector2f position, sf::Vector2f size)
	:UnMoveAble(Resources::RscPic::getPicture(Resources::PictureName::Wall), position, size)
{
	
}

//=====================================		HANDELING		==================================

void Wall::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}
