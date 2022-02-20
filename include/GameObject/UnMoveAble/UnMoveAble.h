#pragma once

#include "GameObject.h"
class UnMoveAble : public GameObject
{
public:
	UnMoveAble(const sf::Texture& picture, sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 40.0f,40.0f });

	virtual void handleCollision(GameObject& gameObject) override = 0;
};