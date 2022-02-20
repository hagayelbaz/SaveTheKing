#include "Teleport.h"
#include "Resources.h"

//=====================================		CONSTRUCOR		==================================

Teleport::Teleport(std::shared_ptr<TeleportManager> manager,bool isEven, sf::Vector2f position, sf::Vector2f size)
	:UnMoveAble(Resources::RscPic::getPicture(Resources::PictureName::Teleport), position, size), m_mnager(manager), m_isEven(isEven)
{
}

//=====================================		PUBLIC		==================================

std::shared_ptr<TeleportManager> Teleport::getManager()
{
	return m_mnager;
}

std::shared_ptr<GameObject> Teleport::getOtherTeleport()
{
	if(m_isEven)
		return m_mnager->getTeleport2();
	return m_mnager->getTeleport1();
}

bool Teleport::isActive()
{
	return m_isActive;
}

void Teleport::activate()
{
	m_isActive = true;
}

void Teleport::deactivate()
{
	m_isActive = false;
}

//=====================================		HANDELING		==================================

void Teleport::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}
