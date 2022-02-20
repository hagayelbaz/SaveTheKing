#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"
#include "ResourcesPicture.h"
#include "ResourecsSound.h"
#include <memory>

// forward declaration
class King;
class Thief;
class Mage;
class Solider;
class Wall;
class Key;
class Gate;
class Fire;
class Orc;
class Teleport;
class Throne;
class Dwarf;
class Gift;


//inheritance from Drawable for simple drawing
class GameObject : public sf::Drawable
{
public:
	GameObject(sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 50.0f,50.0f });

	
	virtual void setPosition(const sf::Vector2f position);
	virtual void setSize(const sf::Vector2f size);
	virtual sf::Vector2f getPosition() const;
	virtual sf::FloatRect getGlobalBounds() const;
	virtual sf::Vector2f getSize() const;
	//to delete from collision handled
	virtual bool isDeleted() const;
	virtual void deleteItem();
	
	//for abstract
	virtual void handleCollision(GameObject& gameObject) = 0;

	virtual void handleCollision(Thief& thief) {};
	virtual void handleCollision(King& king) {}
	virtual void handleCollision(Mage& mage) {}
	virtual void handleCollision(Solider& solider) {}
	virtual void handleCollision(Dwarf& solider) {}
	
	
	virtual void handleCollision(Teleport& teleport) {}
	virtual void handleCollision(Wall& wall) {}
	virtual void handleCollision(Key& key) {}
	virtual void handleCollision(Gate& gate) {}
	virtual void handleCollision(Fire& fire) {}
	virtual void handleCollision(Orc& orc) {}
	virtual void handleCollision(Throne& orc) {}
	virtual void handleCollision(Gift& gift) {}

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::RectangleShape m_shape;

private:
	bool m_deleted = false;
};