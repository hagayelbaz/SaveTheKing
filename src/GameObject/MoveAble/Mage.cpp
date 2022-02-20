#include "Mage.h"

//=====================================		CONSTRUCOR		==================================

Mage::Mage(sf::Vector2f position, sf::Vector2f size)
	:Player(Resources::RscPic::getPicture(Resources::PictureName::Mage), 10, position, size)
{

}

//=====================================		PUBLIC		==================================

PlayersName Mage::getType()
{
	return PlayersName::Mage;
}

//=====================================		HANDELING		==================================

void Mage::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

void Mage::handleCollision(Mage& mage)
{
}

void Mage::handleCollision(Thief& thief)
{
	stepBack();
}

void Mage::handleCollision(King& king)
{
	stepBack();
}

void Mage::handleCollision(Solider& solider)
{
	stepBack();
}

void Mage::handleCollision(Dwarf& solider)
{
	stepBack();
}

void Mage::handleCollision(Throne& orc)
{
}

#include "Gift.h"
void Mage::handleCollision(Gift& gift)
{
	static sf::Sound sound = Resources::RssSound::getSound(Resources::SoundName::Coins);
	sound.play();
	gift.deleteItem();
}

void Mage::handleCollision(Wall& wall)
{
	stepBack();
}

void Mage::handleCollision(Key& key)
{
	
}

void Mage::handleCollision(Gate& gate)
{
	stepBack();
}

#include "Fire.h"
void Mage::handleCollision(Fire& fire)
{
	static sf::Sound sound = Resources::RssSound::getSound(Resources::SoundName::ExtinguishedFire);
	sound.play();
	fire.deleteItem();
}

void Mage::handleCollision(Orc& orc)
{
	stepBack();
}

void Mage::handleCollision(Teleport& teleport)
{
}
