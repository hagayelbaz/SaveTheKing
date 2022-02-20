#pragma once

#include "GameObject.h"
#include "Teleport.h"

class MoveAble : public GameObject
{
public:
	MoveAble(sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 40.0f,40.0f })
		:GameObject(position, size){}


	virtual void move(sf::Time deltaTime) = 0;

	//All heirs must to implement
	//Some will change, will not be accepted as const
	virtual void handleCollision(GameObject& gameObject) override = 0;

	virtual void handleCollision(Thief& thief) override = 0;
	virtual void handleCollision(King& king) override = 0;
	virtual void handleCollision(Mage& mage) override = 0;
	virtual void handleCollision(Solider& solider) override = 0;	
	virtual void handleCollision(Dwarf& solider) override = 0;
	virtual void handleCollision(Teleport& teleport) override = 0;
	virtual void handleCollision(Wall& wall) override = 0;
	virtual void handleCollision(Key& key) override = 0;
	virtual void handleCollision(Gate& gate) override = 0;
	virtual void handleCollision(Fire& fire) override = 0;
	virtual void handleCollision(Orc& orc) override = 0;

	virtual void setSpeed(const float speed);
	float getSpeed()const;
	virtual void setPosition(const sf::Vector2f position) override;

protected:
	virtual void stepBack();
	sf::Vector2f m_lastLocation;
private:
	float m_speed = 250.0f;
	

};