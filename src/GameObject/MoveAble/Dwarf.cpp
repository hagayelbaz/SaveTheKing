#include "Dwarf.h"

//=====================================		CONSTRUCOR		==================================

Dwarf::Dwarf(sf::Vector2f position, sf::Vector2f size)
	:m_diraction(Diraction::Right)
{
	m_shape.setTexture(&Resources::RscPic::getPicture(Resources::PictureName::Dwarf));
	m_shape.setSize(size);
	m_shape.setPosition(position);
	m_lastLocation = position;
	setSpeed(DEFAULT_SPEED);
}

//=====================================		PUBLIC		==================================

void Dwarf::move(sf::Time deltaTime)
{
	m_lastLocation = m_shape.getPosition();

	sf::Vector2f diraction;
	switch (m_diraction)
	{
	case Diraction::Up:diraction = { 0.0f, -1.0f }; break;
	case Diraction::Left:diraction = { -1.0f,0.0f }; break;
	case Diraction::Down:diraction = { 0.0f,1.0f }; break;
	case Diraction::Right:diraction = { 1.0f,0.0f }; break;
	}				
	m_shape.move(diraction * getSpeed() * deltaTime.asSeconds());
}

//=====================================		HANDELING		==================================

void Dwarf::handleCollision(GameObject& gameObject)
{
	stepBack();
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

#include "Thief.h"
void Dwarf::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}

#include "KIng.h"
void Dwarf::handleCollision(King& king)
{
	king.handleCollision(*this);
}

#include "Mage.h"
void Dwarf::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

#include "Solider.h"
void Dwarf::handleCollision(Solider& solider)
{
	solider.handleCollision(*this);
}

void Dwarf::handleCollision(Dwarf& solider)
{
}

void Dwarf::handleCollision(Wall& wall)
{
	stepBack();
	setRandDiraction();
}

void Dwarf::handleCollision(Key& key)
{
	stepBack();
	setRandDiraction();
}

void Dwarf::handleCollision(Gate& gate)
{
	stepBack();
	setRandDiraction();
}

void Dwarf::handleCollision(Fire& fire)
{
	stepBack();
	setRandDiraction();
}

void Dwarf::handleCollision(Orc& orc)
{
	stepBack();
	setRandDiraction();
}

void Dwarf::handleCollision(Teleport& Teleport)
{
	stepBack();
	setRandDiraction();
}

void Dwarf::handleCollision(Throne& Teleport)
{
	stepBack();
	setRandDiraction();
}

//==========================	PRIVATE		=========================

void Dwarf::setRandDiraction()
{
	auto tempDiraction = m_diraction;
	while (tempDiraction == m_diraction)
		m_diraction = static_cast<Diraction>(std::rand() % 4);
}
