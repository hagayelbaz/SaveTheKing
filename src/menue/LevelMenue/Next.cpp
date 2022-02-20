#include "Next.h"

//=====================================		CONSTRUCOR		==================================

Next::Next(sf::Vector2f baseSize, sf::Vector2f basePosition)
{
	setDefaultSetting();
}

//=====================================		PRIVATE		==================================

void Next::setDefaultSetting()
{
	m_control.setTexture(&Resources::RscPic::getPicture(Resources::PictureName::Next));
}
