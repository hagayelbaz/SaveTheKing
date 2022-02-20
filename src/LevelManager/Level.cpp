#include "Level.h"

//=====================================		CONSTRUCOR		==================================

Level::Level(const int levelNum)
	:m_levelNumber(levelNum)
{
	refresh();
}

//=====================================		PUBLIC		==================================

void Level::next()
{
	*this = Level(m_levelNumber + 1);
}

void Level::moveTo(const int levelNumber)
{
	*this = Level(levelNumber);
}

float Level::getTimet() const
{
	return m_time;
}

bool Level::isLegal()
{
	return refresh();//if file changed
}

int Level::getLevelNumber() const
{
	return m_levelNumber;
}

std::map<PlayersName, std::shared_ptr<Player>>& Level::getPlayers()
{
	return m_players;
}

std::vector<std::shared_ptr<GameObject>>& Level::getObjects()
{
	return m_objects;
}

std::vector<std::shared_ptr<GameObject>>& Level::getDwarfs()
{
	return m_dwarf;
}


//=====================================		PRIVATE		==================================

void Level::loadFromString()
{
	for (int i = 0; i < m_board.size(); i++)
		insertLine(m_board[i], i);
}
void Level::addTeleport(int& teleportCounter, sf::Vector2f position)
{
	teleportCounter++;

	if (teleportCounter % 2 != 0)
	{
		m_teleportManagers.insert(m_teleportManagers.begin(), std::make_shared<TeleportManager>());
		m_objects.push_back(std::make_shared<Teleport>(Teleport(m_teleportManagers[0], true, position, m_sizeObj)));
		m_teleportManagers[0]->setTeleport1(m_objects[m_objects.size() - 1]);
		return;
	}
	m_objects.push_back(std::make_shared<Teleport>(Teleport(m_teleportManagers[0], false, position, m_sizeObj)));
	m_teleportManagers[0]->setTeleport2(m_objects[m_objects.size() - 1]);
}
void Level::addRandGift(const sf::Vector2f position)
{
	int i = std::rand() % 3;
	switch (i)
	{ 
	case 0:m_objects.push_back(std::make_shared<GiftTimeAdd>(GiftTimeAdd(position, m_sizeObj))); break;
	case 1:m_objects.push_back(std::make_shared<GiftTimeDecrease>(GiftTimeDecrease(position, m_sizeObj))); break;
	case 2:m_objects.push_back(std::make_shared<GiftDwarfRemover>(GiftDwarfRemover(position, m_sizeObj))); break;
	default:break;
	}
}
void Level::insertLine(const std::string line, const int lineNum)
{
	static int teleportCounter = 0;

	for (int i = 0; i < line.size(); i++)
	{
		auto location = sf::Vector2f(m_sizeObj.x * i, m_sizeObj.y * lineNum);
		switch (line[i])
		{
		case 'K':   m_players.insert({PlayersName::King ,std::make_shared<King>(King(location, m_sizePlayers)) }); break;
		case 'W':   m_players.insert({PlayersName::Solider ,std::make_shared<Solider>(Solider(location, m_sizePlayers)) }); break;
		case 'T':   m_players.insert({PlayersName::Thief ,std::make_shared<Thief>(Thief(location, m_sizePlayers)) }); break;
		case 'M':   m_players.insert({PlayersName::Mage ,std::make_shared<Mage>(Mage(location, m_sizePlayers)) }); break;

		case '^':	m_dwarf.push_back(std::make_shared<Dwarf>(Dwarf(location, m_sizeDwarf))); break;

		case '#':   m_objects.push_back(std::make_shared<Gate>(Gate(location, m_sizeObj))); break;
		case '*':   m_objects.push_back(std::make_shared<Fire>(Fire(location, m_sizeObj))); break;
		case 'F':   m_objects.push_back(std::make_shared<Key>(Key(location, m_sizeObj))); break;
		case '!':   m_objects.push_back(std::make_shared<Orc>(Orc(location, m_sizeObj))); break;
		case '@':   m_objects.push_back(std::make_shared<Throne>(Throne(location, m_sizeObj))); break;
		case '=':	m_objects.push_back(std::make_shared<Wall>(Wall(location, m_sizeObj))); break;
		case '$':	addRandGift(location); break;
		case 'X':   addTeleport(teleportCounter, location);break;

		default: break;
		}
	}
}


bool Level::refresh()
{
	auto level = std::ifstream("Level" + std::to_string(m_levelNumber) + ".txt");

	if (!level.good()) return false;

	level >> m_time;

	m_board.clear();
	m_objects.clear();
	m_players.clear();
	m_dwarf.clear();

	for (std::string line; std::getline(level, line); )
		m_board.push_back(line);

	loadFromString();

	return true;
}