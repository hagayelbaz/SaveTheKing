#include "TeleportManager.h"

//=====================================		PUBLIC		==================================

void TeleportManager::setTeleport1(std::shared_ptr<GameObject> teleport)
{
	m_teleport1 = teleport;
}

void TeleportManager::setTeleport2(std::shared_ptr<GameObject> teleport)
{
	m_teleport2 = teleport;
}

std::shared_ptr<GameObject> TeleportManager::getTeleport1()
{
	return m_teleport1;
}

std::shared_ptr<GameObject> TeleportManager::getTeleport2()
{
	return m_teleport2;
}
