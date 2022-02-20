#include "Gate.h"

//=====================================		CONSTRUCOR		==================================

Gate::Gate( sf::Vector2f position, sf::Vector2f size)
	:UnMoveAble(Resources::RscPic::getPicture(Resources::PictureName::Gate), position, size)
{

}

//=====================================		HANDELING		==================================

void Gate::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}