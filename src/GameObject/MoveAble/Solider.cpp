#include "Solider.h"

//=====================================		CONSTRUCOR		==================================

Solider::Solider(sf::Vector2f position, sf::Vector2f size)
	:Player(Resources::RscPic::getPicture(Resources::PictureName::Solider), 7 , position, size)
{

}

//=====================================		PUBLIC		==================================

PlayersName Solider::getType()
{
	return PlayersName::Solider;
}

//=====================================		HANDELING		==================================

void Solider::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

void Solider::handleCollision(Solider& solider)
{
	
}

void Solider::handleCollision(Dwarf& solider)
{
	stepBack();
}

void Solider::handleCollision(Throne& orc)
{
}

#include "Gift.h"
void Solider::handleCollision(Gift& gift)
{
	static sf::Sound sound = Resources::RssSound::getSound(Resources::SoundName::Coins);
	sound.play();
	gift.deleteItem();
}

void Solider::handleCollision(Wall& wall)
{
	stepBack();
}

void Solider::handleCollision(Key& key)
{

}

void Solider::handleCollision(Gate& gate)
{
	stepBack();
}

void Solider::handleCollision(Fire& fire)
{
	stepBack();
}

#include "Orc.h"
void Solider::handleCollision(Orc& orc)
{
	static sf::Sound sound = Resources::RssSound::getSound(Resources::SoundName::Fight);
	sound.play();
	orc.deleteItem();
}

void Solider::handleCollision(Thief& thief)
{
	stepBack();
}

void Solider::handleCollision(King& King)
{
	stepBack();
}

void Solider::handleCollision(Mage& mage)
{
	stepBack();
}

void Solider::handleCollision(Teleport& teleport)
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
