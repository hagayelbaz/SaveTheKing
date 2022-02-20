#pragma once

#include "UnMoveAble.h"

class Key : public UnMoveAble
{
public:
	Key(sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 40.0f,40.0f });

	void takeKey();
	void handleCollision(GameObject& gameObject) override;
};