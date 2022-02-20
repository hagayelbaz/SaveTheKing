#pragma once

#include "GameObject.h"
#include "Resources.h"
#include "Solider.h"
#include "Thief.h"
#include "King.h"
#include "Mage.h"
#include "Wall.h"
#include "Key.h"
#include "Gate.h"
#include "Fire.h"
#include "Orc.h"
#include "Level.h"

class CollisionHandled
{
public:
	CollisionHandled(
		std::map<PlayersName,std::shared_ptr<Player>>& players,
		std::vector<std::shared_ptr<GameObject>>& objects, 
		std::vector<std::shared_ptr<GameObject>>& dwarfs);

	//for next level
	CollisionHandled& operator=(const CollisionHandled& rhs);

	void handled(Player* &currentPlayer);
	bool isLevelEnd();
	int getTimeGift() const;

private:
	void endLevel();

	//delet item deleted
	void resetArray(std::vector<std::shared_ptr<GameObject>>& orcToAdd);
	//fall key , add time, end level , etc
	void specialCasesDeleted(std::shared_ptr<GameObject>& item,std::vector<std::shared_ptr<GameObject>>& orcToAdd);
	//player collision with static item
	void handledObjects(Player*& currentPlayer);
	//player collision with player
	void handledPlayers(Player*& currentPlayer);
	
	void handledItem(Player*& currentPlayer, GameObject& item);
	void handledTeleport(Player*& currentPlayer,GameObject& teleport);

	bool m_levelEnd = false;
	int m_timeGift = 0;
	std::map<PlayersName, std::shared_ptr<Player>>& m_players;
	std::vector<std::shared_ptr<GameObject>>& m_objects;
	std::vector<std::shared_ptr<GameObject>>& m_dwarfs;
};