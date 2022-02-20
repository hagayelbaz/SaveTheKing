#include "Orc.h"

//=====================================		CONSTRUCOR		==================================

Orc::Orc(sf::Vector2f position, sf::Vector2f size)
	:UnMoveAble(Resources::RscPic::getPicture(Resources::PictureName::Orc), position, size)
{

}

//=====================================		HANDELING		==================================

void Orc::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//=====================================		PUBLIC		==================================

#include "Key.h"
std::shared_ptr<GameObject> Orc::createKey()
{
	auto keyType = std::make_shared<Key>();
	keyType->setSize(this->getSize());
	keyType->setPosition(this->getPosition());
	return keyType;
}
