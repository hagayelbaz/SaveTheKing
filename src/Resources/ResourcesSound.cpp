#include "ResourecsSound.h"


namespace Resources
{
	//=====================================		CONSTRUCOR/PRIVATE		==================================

	RssSound::RssSound()
	{
		loadSound();
	}
	
	//=====================================		PUBLIC		==================================
	//==============================	get as sound or buffer		==========================

	sf::SoundBuffer& RssSound::getSoundBuffer(const SoundName sound)
	{
		static RssSound resources = RssSound();
		return resources.m_res.at(sound);
	}
	sf::Sound RssSound::getSound(const SoundName picture)
	{
		sf::Sound sound;
		sound.setBuffer(RssSound::getSoundBuffer(picture));
		return sound;
	}

	//=====================================		PRIVATE		==================================

	void RssSound::loadSound()
	{
		sf::SoundBuffer rscTada = sf::SoundBuffer();
		rscTada.loadFromFile("tada.wav");
		m_res.insert({ SoundName::Tada, rscTada });

		sf::SoundBuffer rscClick = sf::SoundBuffer();
		rscClick.loadFromFile("click.wav");
		m_res.insert({ SoundName::Click, rscClick });

		sf::SoundBuffer rscEndLevel = sf::SoundBuffer();
		rscEndLevel.loadFromFile("endLevel.wav");
		m_res.insert({ SoundName::EndLevel, rscEndLevel });

		sf::SoundBuffer rscFail = sf::SoundBuffer();
		rscFail.loadFromFile("fail.wav");
		m_res.insert({ SoundName::Fail, rscFail });

		sf::SoundBuffer rscReadyGo = sf::SoundBuffer();
		rscReadyGo.loadFromFile("readyGo.wav");
		m_res.insert({ SoundName::ReadyGo, rscReadyGo });

		sf::SoundBuffer rscBackGround = sf::SoundBuffer();
		rscBackGround.loadFromFile("backGround.wav");
		m_res.insert({ SoundName::BackGround, rscBackGround });

		sf::SoundBuffer rscCoins = sf::SoundBuffer();
		rscCoins.loadFromFile("coins.wav");
		m_res.insert({ SoundName::Coins, rscCoins });

		sf::SoundBuffer rscGameSound = sf::SoundBuffer();
		rscGameSound.loadFromFile("gameSound.wav");
		m_res.insert({ SoundName::GameSound, rscGameSound });

		sf::SoundBuffer rscFight = sf::SoundBuffer();
		rscFight.loadFromFile("fight.wav");
		m_res.insert({ SoundName::Fight, rscFight });

		sf::SoundBuffer rscCountDown = sf::SoundBuffer();
		rscCountDown.loadFromFile("countdown.wav");
		m_res.insert({ SoundName::CountDown, rscCountDown });

		sf::SoundBuffer rscExtinguishedFire = sf::SoundBuffer();
		rscExtinguishedFire.loadFromFile("Extinguishedfire.wav");
		m_res.insert({ SoundName::ExtinguishedFire, rscExtinguishedFire });

		sf::SoundBuffer rscOpenDoor = sf::SoundBuffer();
		rscOpenDoor.loadFromFile("opendoor.wav");
		m_res.insert({ SoundName::OpenDoor, rscOpenDoor });

		sf::SoundBuffer rscTeleport = sf::SoundBuffer();
		rscTeleport.loadFromFile("teleport.wav");
		m_res.insert({ SoundName::Teleport, rscTeleport });
	}	
}