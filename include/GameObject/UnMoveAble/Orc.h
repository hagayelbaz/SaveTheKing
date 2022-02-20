#pragma once

#include "UnMoveAble.h"

class Orc : public UnMoveAble
{
public:
	Orc(sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 40.0f,40.0f });

	void handleCollision(GameObject& gameObject) override;
	//fall key
	std::shared_ptr<GameObject> createKey();
};