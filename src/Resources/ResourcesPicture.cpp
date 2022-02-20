

#include "ResourcesPicture.h"

namespace Resources
{
	//=====================================		CONSTRUCOR/PRIVATE		==================================

	RscPic::RscPic()
	{
		loadImages();
	}

	//=====================================		PRIVATE		==================================

	void RscPic::loadImages()
	{
		sf::Texture resKing = sf::Texture();
		resKing.loadFromFile("king.png");
		m_res.insert({ PictureName::King, resKing });

		sf::Texture resTeleport = sf::Texture();
		resTeleport.loadFromFile("teleport.png");
		m_res.insert({ PictureName::Teleport, resTeleport });

		sf::Texture resGift = sf::Texture();
		resGift.loadFromFile("gift.png");
		m_res.insert({ PictureName::Gift, resGift });

		sf::Texture resThief = sf::Texture();
		resThief.loadFromFile("thief.png");
		m_res.insert({ PictureName::Thief, resThief });

		sf::Texture resMage = sf::Texture();
		resMage.loadFromFile("mage.png");
		m_res.insert({ PictureName::Mage, resMage });

		sf::Texture resSolider = sf::Texture();
		resSolider.loadFromFile("solider.png");
		m_res.insert({ PictureName::Solider, resSolider });

		sf::Texture resBackColor = sf::Texture();
		resBackColor.loadFromFile("backColor.png");
		m_res.insert({ PictureName::BackColor, resBackColor });

		sf::Texture resWall = sf::Texture();
		resWall.loadFromFile("wall.png");
		m_res.insert({ PictureName::Wall, resWall });

		sf::Texture resKey = sf::Texture();
		resKey.loadFromFile("Key.png");
		m_res.insert({ PictureName::Key, resKey });

		sf::Texture resGate = sf::Texture();
		resGate.loadFromFile("Gate.png");
		m_res.insert({ PictureName::Gate, resGate });

		sf::Texture resFire = sf::Texture();
		resFire.loadFromFile("Fire.png");
		m_res.insert({ PictureName::Fire, resFire });

		sf::Texture resOrc = sf::Texture();
		resOrc.loadFromFile("Orc.png");
		m_res.insert({ PictureName::Orc, resOrc });

		sf::Texture resArrow = sf::Texture();
		resArrow.loadFromFile("arrow.png");
		m_res.insert({ PictureName::Arrow, resArrow });

		sf::Texture resThrone = sf::Texture();
		resThrone.loadFromFile("throne.png");
		m_res.insert({ PictureName::Throne, resThrone });

		sf::Texture resPlay = sf::Texture();
		resPlay.loadFromFile("play.png");
		m_res.insert({ PictureName::Play, resPlay });

		sf::Texture resExit = sf::Texture();
		resExit.loadFromFile("exit.png");
		m_res.insert({ PictureName::Exit, resExit });

		sf::Texture resLevel = sf::Texture();
		resLevel.loadFromFile("level.png");
		m_res.insert({ PictureName::Level, resLevel });

		sf::Texture resLock = sf::Texture();
		resLock.loadFromFile("lock.png");
		m_res.insert({ PictureName::Lock, resLock });

		sf::Texture resInstructions = sf::Texture();
		resInstructions.loadFromFile("Instructions.png");
		m_res.insert({ PictureName::Instructions, resInstructions });

		sf::Texture resNext = sf::Texture();
		resNext.loadFromFile("next.png");
		m_res.insert({ PictureName::Next, resNext });

		sf::Texture resDwarf = sf::Texture();
		resDwarf.loadFromFile("dwarf.png");
		m_res.insert({ PictureName::Dwarf, resDwarf });
	}

	//=====================================		PUBLIC		==================================

	sf::Texture& RscPic::getPicture(const PictureName picture)
	{
		static RscPic resources = RscPic();
		return resources.m_res.at(picture);
	}
}