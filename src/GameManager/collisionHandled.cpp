#include "collisionHandled.h"


//=====================================		CONSTRUCOR		==================================

CollisionHandled::CollisionHandled(
    std::map<PlayersName, std::shared_ptr<Player>>& players,
    std::vector<std::shared_ptr<GameObject>>& objects,
    std::vector<std::shared_ptr<GameObject>>& dwarfs)
	:m_objects(objects), m_players(players),m_dwarfs(dwarfs)
{
}

//=====================================		OPERATOR		===============================

CollisionHandled& CollisionHandled::operator=(const CollisionHandled& rhs)
{
    this->m_levelEnd = rhs.m_levelEnd;
    this->m_objects = rhs.m_objects;
    this->m_players = rhs.m_players;
    this->m_dwarfs = rhs.m_dwarfs;
    return *this;
}

//=====================================		HANDELING-PUBLIC		======================

void CollisionHandled::handled(Player* &currentPlayer)
{
    handledObjects(currentPlayer);
    handledPlayers(currentPlayer);  
}

//=====================================		PUBLIC		==================================

bool CollisionHandled::isLevelEnd()
{
    return m_levelEnd;
}

int CollisionHandled::getTimeGift() const
{
    return m_timeGift;
}

void CollisionHandled::endLevel()
{
    m_levelEnd = true;
}

//=====================================		HANDELING-PRIVATE		======================
void CollisionHandled::handledObjects(Player*& currentPlayer)
{
    m_timeGift = 0;
    std::vector<std::shared_ptr<GameObject>> tempOrc;//for add in for

    for (auto& item : m_objects)
    {
        handledItem(currentPlayer, *item);
        if (!item->isDeleted()) continue;
        specialCasesDeleted(item, tempOrc);
        if (m_levelEnd)
            return;
    }
    resetArray(tempOrc);
}

void CollisionHandled::handledPlayers(Player*& currentPlayer)
{
    for (auto& item : m_players)
        if (currentPlayer->getGlobalBounds().intersects(item.second.get()->getGlobalBounds()))
            item.second->handleCollision(*currentPlayer);

}

void CollisionHandled::handledItem(Player*& currentPlayer, GameObject& item)
{
    if (currentPlayer->getGlobalBounds().intersects(item.getGlobalBounds()))
        item.handleCollision(*currentPlayer);
    else
        handledTeleport(currentPlayer, item);

    for (auto& dwarf : m_dwarfs)
    {
        if (currentPlayer->getGlobalBounds().intersects(dwarf->getGlobalBounds()))
            dwarf->handleCollision(*currentPlayer);
        if (dwarf->getGlobalBounds().intersects(item.getGlobalBounds()))
            item.handleCollision(*dwarf);
    }
}

void CollisionHandled::handledTeleport(Player*& currentPlayer, GameObject& teleport)
{
    if (typeid(teleport) != typeid(Teleport))
        return;

    Teleport& temp = dynamic_cast<Teleport&>(teleport);

    for (auto& item : m_players)
    {
        if (item.second.get() == currentPlayer)
            continue;
        if (item.second.get()->getGlobalBounds().intersects(temp.getGlobalBounds()))//if second teleport not empty
            return;
    }
    temp.activate();
}
//=====================================		PRIVATE		==================================

void CollisionHandled::resetArray(std::vector<std::shared_ptr<GameObject>>& orcToAdd)
{
    for (auto& item : m_objects)
        std::erase_if(m_objects, [](const std::shared_ptr<GameObject>& item) { return item.get()->isDeleted(); });
    for (auto& item : orcToAdd)
        m_objects.push_back(item);
}

void CollisionHandled::specialCasesDeleted(std::shared_ptr<GameObject>& item, std::vector<std::shared_ptr<GameObject>>& orcToAdd)
{
    if (typeid(*item) == typeid(GiftTimeAdd) || typeid(*item) == typeid(GiftTimeDecrease))
        m_timeGift += ((GiftTime&)*item).take();
    if (typeid(*item) == typeid(Orc))
        orcToAdd.push_back(((Orc&)*item).createKey());//temp for add in the loop
    if (typeid(*item) == typeid(Throne))
        endLevel();
    if (typeid(*item) == typeid(GiftDwarfRemover))
        m_dwarfs.clear();
}







