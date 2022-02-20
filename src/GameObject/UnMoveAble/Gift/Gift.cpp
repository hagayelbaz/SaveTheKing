#include "Gift.h"

//=====================================		CONSTRUCOR		==================================

Gift::Gift(sf::Vector2f position, sf::Vector2f size)
	:UnMoveAble(Resources::RscPic::getPicture(Resources::PictureName::Gift), position, size){}

//=====================================		HANDELING		==================================

void Gift::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}
