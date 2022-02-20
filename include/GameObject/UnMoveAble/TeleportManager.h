#pragma once
#include <memory>
#include "GameObject.h"

class TeleportManager {
public:
	void setTeleport1(std::shared_ptr<GameObject> teleport);
	void setTeleport2(std::shared_ptr<GameObject> teleport);

	std::shared_ptr<GameObject> getTeleport1();
	std::shared_ptr<GameObject> getTeleport2();
private:
	std::shared_ptr<GameObject> m_teleport1, m_teleport2;
};