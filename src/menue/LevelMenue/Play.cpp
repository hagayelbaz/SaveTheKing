#include "Play.h"

//=====================================		CONSTRUCOR		==================================

Play::Play(sf::Vector2f baseSize, sf::Vector2f basePosition)
{
	setDefaultSetting();
}

//=====================================		PRIVATE		==================================

void Play::setDefaultSetting()
{
	m_control.setTexture(&Resources::RscPic::getPicture(Resources::PictureName::Play));
}
