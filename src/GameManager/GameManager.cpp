#include "GameManager.h"

//=====================================		CONSTRUCOR		==================================

GameManager::GameManager()
	:m_collision(m_players,m_objects,m_dwarfs)
{	
	m_soundMain = Resources::RssSound::getSound(Resources::SoundName::GameSound);
	m_soundReadygo = Resources::RssSound::getSound(Resources::SoundName::ReadyGo);
	m_soundCountDown = Resources::RssSound::getSound(Resources::SoundName::CountDown);
	
	m_soundMain.setLoop(true);
	m_soundCountDown.setLoop(true);
}

//=====================================		PUBLIC		==================================

void GameManager::show(sf::RenderWindow& window)
{
	if (!window.isOpen())return;

	sf::Event event;
	startGame(window);
	m_deltaTime = m_clock.restart();

	while (window.isOpen())
	{		
		window.clear(sf::Color::White);
		window.draw(m_backGround);	
		
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: window.close(); break;
			case sf::Event::KeyPressed: 
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					m_soundMain.stop();
					m_soundCountDown.stop();
					return;
				}
			    if (event.key.code == sf::Keyboard::P) nextPlayer(); break;
			}
			}
			
		}	
		
		play(window);
		if (endLevel())return;
		window.display();
	}
}


void GameManager::setLevel(Level& level)
{
	m_level = level;
	m_levelNumber = level.getLevelNumber();
	resetLevel();
}


//=====================================		PRIVATE		==================================

//=====================================	   END LEVEL	==================================
bool GameManager::endLevel()
{
	if (m_timer.getTimeF() <= 0)
	{
		fail(); return true;
	}
	if (m_collision.isLevelEnd())
	{		
		win(); return true;
	}
	return false;
}
void GameManager::fail()
{
	m_soundMain.stop();
	m_soundCountDown.stop();
	static auto sound = Resources::RssSound::getSound(Resources::SoundName::Fail);
	sound.play();
	sf::sleep(sf::Time(sf::seconds(3)));
}

void GameManager::win()
{
	if (m_levelNumber >= Data::getDoneLevels())
		Data::setOpen();//remove lock from next level
	m_soundCountDown.stop();
	m_soundMain.stop();
	static auto sound = Resources::RssSound::getSound(Resources::SoundName::EndLevel);
	sound.play();
	sf::sleep(sf::Time(sf::seconds(3)));
}


//==================================	START GAME	===========================

//restart level
void GameManager::startGame(sf::RenderWindow& window)
{
	m_backGround.setSize({ float(window.getSize().x), float(window.getSize().y) });
	m_backGround.setTexture(&Resources::RscPic::getPicture(Resources::PictureName::BackColor));

	m_soundReadygo.play();
	sf::sleep(sf::Time(sf::seconds(4)));
	
	m_soundMain.play();

	m_timer.startTimer(m_level.getTimet());
}

//restart items
void GameManager::resetLevel()
{
	m_players = m_level.getPlayers();
	m_objects = m_level.getObjects();
	m_dwarfs = m_level.getDwarfs();

	this->m_collision = CollisionHandled(m_players, m_objects, m_dwarfs);

	m_currentPlayer = m_players[PlayersName::King].get();
	m_currentPlayer->point();
	m_soundMain.setVolume(100);
}

//==========================	GAME	===========================
void GameManager::play(sf::RenderWindow& window)
{
	if (m_timer.getTimeF() <= 10.f && m_soundCountDown.getStatus() != sf::Sound::Playing)
	{
		m_soundMain.setVolume(60);
		m_soundCountDown.play();
	}

	
	draw(window);
	m_deltaTime = m_clock.restart();

	for (auto& item : m_dwarfs)
		((Dwarf*)(item.get()))->move(m_deltaTime);

	m_currentPlayer->move(m_deltaTime);	

	m_collision.handled(m_currentPlayer);

	m_timer.addTime(m_collision.getTimeGift());
}


void GameManager::draw(sf::RenderWindow& window)
{
	for (auto& item : m_objects)
		window.draw(*item.get());
	for (auto& item : m_dwarfs)
		window.draw(*item.get());
	for (auto& item : m_players)
		window.draw(*item.second.get());

	window.draw(StatusLine::show(m_players, m_timer, { 0.0f,0.0f }, { float(window.getSize().x) ,100.0f }));
}

void GameManager::nextPlayer()
{
	m_currentPlayer->removePoint();
	switch (m_currentPlayer->getType())
	{
	case PlayersName::King: m_currentPlayer = m_players[PlayersName::Mage].get(); break;
	case PlayersName::Mage: m_currentPlayer = m_players[PlayersName::Solider].get(); break;
	case PlayersName::Solider: m_currentPlayer = m_players[PlayersName::Thief].get(); break;
	case PlayersName::Thief: m_currentPlayer = m_players[PlayersName::King].get(); break;
	}
	m_currentPlayer->point();
}