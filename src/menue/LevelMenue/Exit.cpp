#include "Exit.h"

//=====================================		CONSTRUCOR		==================================

Exit::Exit(sf::Vector2f baseSize, sf::Vector2f basePosition)
{
	setDefaultSetting();
}

//=====================================		PRIVATE		==================================

void Exit::setDefaultSetting()
{
	m_control.setTexture(&Resources::RscPic::getPicture(Resources::PictureName::Exit));
}

