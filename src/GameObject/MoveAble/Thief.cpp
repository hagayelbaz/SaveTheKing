#include "Thief.h"

//=====================================		CONSTRUCOR		==================================

Thief::Thief(sf::Vector2f position, sf::Vector2f size)
	:Player(Resources::RscPic::getPicture(Resources::PictureName::Thief), 3 ,position , size)
{

}

//=====================================		PUBLIC		==================================

PlayersName Thief::getType()
{
	return PlayersName::Thief;
}

//=====================================		HANDELING		==================================

void Thief::handleCollision(GameObject& gameObject)
{	
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

void Thief::handleCollision(Thief& thief)
{
	
}

void Thief::handleCollision(King& King)
{
	stepBack();
}

void Thief::handleCollision(Mage& mage)
{
	stepBack();
}

void Thief::handleCollision(Solider& solider)
{
	stepBack();
}

void Thief::handleCollision(Dwarf& solider)
{
	stepBack();
}

void Thief::handleCollision(Throne& orc)
{

}

#include "Gift.h"
void Thief::handleCollision(Gift& gift)
{
	static sf::Sound sound = Resources::RssSound::getSound(Resources::SoundName::Coins);
	sound.play();
	gift.deleteItem();
}

void Thief::handleCollision(Wall& wall)
{
	stepBack();
}

#include "Key.h"
void Thief::handleCollision(Key& key)
{
	if (!hasKey())
	{		
		key.deleteItem();
		m_key = true;
		static auto sound = Resources::RssSound::getSound(Resources::SoundName::Coins);
		sound.play();
	}
}

#include "Gate.h"
void Thief::handleCollision(Gate& gate)
{
	if (hasKey())
	{
		static auto sound = Resources::RssSound::getSound(Resources::SoundName::OpenDoor);
		sound.play();
		gate.deleteItem();
		m_key = false;
	}
	else
		stepBack();
}

void Thief::handleCollision(Fire& fire)
{
	stepBack();
}

void Thief::handleCollision(Orc& orc)
{
	stepBack();
}


void Thief::handleCollision(Teleport& teleport)
{
	if (teleport.isActive() &&
		dynamic_cast<Teleport*>(teleport.getOtherTeleport().get())->isActive())
	{
		this->setPosition(teleport.getOtherTeleport()->getPosition());
		dynamic_cast<Teleport*>(teleport.getOtherTeleport().get())->deactivate();

		static sf::Sound sound = Resources::RssSound::getSound(Resources::SoundName::Teleport);
		sound.play();
	}
}

bool Thief::hasKey()
{
	return m_key;
}


