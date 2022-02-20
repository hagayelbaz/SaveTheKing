#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include "GameObject.h"
#include "King.h"
#include "Thief.h"
#include "Mage.h"
#include "Solider.h"
#include "Wall.h"
#include "Key.h"
#include "Gate.h"
#include "Fire.h"
#include "Orc.h"
#include "Throne.h"
#include "Teleport.h"
#include "TeleportManager.h"  
#include "TimeClock.h"  
#include "Dwarf.h"
#include "GiftTimeAdd.h"
#include "GiftTimeDecrease.h"
#include "GiftDwarfRemover.h"

class Level
{
public:
	Level(const int levelNum = 1);

	//move to next level
	void next();
	//move to specific level
	void moveTo(const int levelNumber);
	//get level limit time
	float getTimet() const;
	//if open file successed
	bool isLegal();
	int getLevelNumber() const;

	std::vector<std::shared_ptr<GameObject>>& getObjects();
	std::vector<std::shared_ptr<GameObject>>& getDwarfs();
	std::map<PlayersName,std::shared_ptr<Player>>& getPlayers();

private:

	//Consumed if the file changed while playing, need to know if it is valid
	bool refresh();

	//loaded to vectores
	void loadFromString();
	void insertLine(const std::string line, const int lineNum);
	
	void addTeleport(int& teleportCounter, const sf::Vector2f position);
	void addRandGift(const sf::Vector2f position);

	sf::Vector2f m_screeenSize;
	int m_levelNumber, m_time = 0;
		
	std::vector<std::shared_ptr<GameObject>> m_objects;
	std::vector<std::shared_ptr<GameObject>> m_dwarf;
	std::map<PlayersName, std::shared_ptr<Player>> m_players;
	std::vector<std::shared_ptr<TeleportManager>> m_teleportManagers;

	std::vector<std::string> m_board;

	//default sizes 
	sf::Vector2f m_sizeObj = sf::Vector2f{ 50.0f, 50.0f };
	sf::Vector2f m_sizePlayers = sf::Vector2f{ 40.0f, 40.0f };
	sf::Vector2f m_sizeDwarf = sf::Vector2f{ 45.0f, 45.0f };	
};
