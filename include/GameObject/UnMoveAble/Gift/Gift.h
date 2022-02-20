#pragma once


#include "UnMoveAble.h"

class Gift : public UnMoveAble
{

public:
	Gift(sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 40.0f,40.0f });

	virtual void handleCollision(GameObject& gameObject) override;
};
