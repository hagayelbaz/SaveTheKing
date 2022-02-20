#pragma once
#include "UnMoveAble.h"

#include "TeleportManager.h";

class Teleport : public UnMoveAble {
public:
	Teleport(std::shared_ptr<TeleportManager> manager, bool isEven, sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 40.0f,40.0f });
	
	std::shared_ptr<TeleportManager> getManager();
	std::shared_ptr<GameObject> getOtherTeleport();

	void handleCollision(GameObject& gameObject) override;
	//get state
	bool isActive();
	//turn off / on
	void activate();
	void deactivate();

private:
	std::shared_ptr<TeleportManager> m_mnager;
	const bool m_isEven;
	bool m_isActive = true;
};