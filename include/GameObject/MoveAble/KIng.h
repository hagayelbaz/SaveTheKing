#pragma once 

#include "Player.h"

class King : public Player
{
public:
	King(sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 40.0f,40.0f });

	virtual PlayersName getType() override;

	virtual void handleCollision(GameObject& gameObject) override;

	virtual void handleCollision(Thief& thief) override;
	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Solider& solider) override;
	
	virtual void handleCollision(Dwarf& solider) override;


	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Key& key) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(Fire& fire) override;
	virtual void handleCollision(Orc& orc) override;
	virtual void handleCollision(Teleport& Teleport) override;
	virtual void handleCollision(Throne& Teleport) override;
	virtual void handleCollision(Gift& gift) override;
};