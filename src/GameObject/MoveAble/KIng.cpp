#include "King.h"


//=====================================		CONSTRUCOR		==================================

King::King(sf::Vector2f position, sf::Vector2f size)
	:Player(Resources::RscPic::getPicture(Resources::PictureName::King), 3 ,position, size)
{
	
}

//=====================================		PUBLIC		==================================

PlayersName King::getType()
{
	return PlayersName::King;
}

//=====================================		HANDELING		==================================

void King::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

void King::handleCollision(King& king)
{
	
}

void King::handleCollision(Thief& thief)
{
	stepBack();
}

void King::handleCollision(Solider& solider)
{
	stepBack();
}

void King::handleCollision(Dwarf& solider)
{
	stepBack();
}

void King::handleCollision(Mage& mage)
{
	stepBack();
}

void King::handleCollision(Key& key)
{

}

void King::handleCollision(Gate& gate)
{
	stepBack();
}

void King::handleCollision(Fire& fire)
{
	stepBack();
}

void King::handleCollision(Orc& orc)
{
	stepBack();
}

#include "Throne.h"
void King::handleCollision(Throne& throne)
{
	throne.deleteItem();
}

#include "Gift.h"
void King::handleCollision(Gift& gift)
{
	static sf::Sound sound = Resources::RssSound::getSound(Resources::SoundName::Coins);
	sound.play();
	gift.deleteItem();
}

void King::handleCollision(Teleport& teleport)
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

void King::handleCollision(Wall& wall)
{
	stepBack();
}



