#include "LevelMenue.h"

//=====================================		CONSTRUCOR		==================================

LevelMenue::LevelMenue(sf::Vector2f position, sf::Vector2f size)
	:m_position(position) ,m_size(size)
{
	setDefaultSetting();
}

//=====================================		SET		==================================

void LevelMenue::setSize(const sf::Vector2f size)
{
	m_size = size;
	setDefaultSetting();
}

void LevelMenue::setPosition(const sf::Vector2f position)
{
	m_position = position;
	setDefaultSetting();
}

//=====================================		GET		==================================

int LevelMenue::getsSelectedLevel()
{
	return m_selectedLevel;
}

State LevelMenue::getCurrentState(sf::Event& event)
{
	for (auto& item : m_levels)
	{
		if (item.getCurrentState(event) == State::Pressed)
			return State::Pressed;
		if (item.getCurrentState(event) == State::Moved)
			return State::Moved;	
	}
	return State::Normal;
}
//=====================================		HANDELING		==================================

void LevelMenue::eventHandled(sf::RenderWindow& window, sf::Event& event)
{
	for (auto& item : m_levels)
	{
		item.eventHandled(window, event);
		if (item.getLastState() == State::Pressed)
			m_selectedLevel = item.getLevelNumber();//update how's selected
	}
}

//=====================================		PUBLIC		==================================

void LevelMenue::mousePressed(sf::RenderWindow& window, sf::Event& event)
{
	for (auto& item : m_levels)
		item.mousePressed(window, event);
}

//=====================================		PRIVATE		==================================

void LevelMenue::refresh()
{
	m_levels.clear();
	loadFromFile();
}

void LevelMenue::setDefaultSetting()
{
	m_levels.clear();
	m_position += MARGIN;
	m_size -= MARGIN * 4.0f;//fit size and pos

	m_border.setSize(m_size);
	m_border.setPosition(m_position);
	m_border.setFillColor(BACK_COLOR);
	m_border.setOutlineThickness(3);
	m_border.setOutlineColor(sf::Color::Black);

	loadFromFile();
}

void LevelMenue::add(bool lock, int levelNum)
{
	sf::Vector2f startPos = m_position + DEFAULT_SIZE / 2.0f;

	SelectLevel level;
	level.setPosition(startPos);
	for (auto& item : m_levels)
	{
		if (item.getGlobalBounds().intersects(level.getGlobalBounds()))
		{
			startPos.x += level.getSize().x + SPACE;
			level.setPosition(startPos);
		}
		if (startPos.x > m_size.x - m_position.x)
		{
			startPos.x = m_position.x + DEFAULT_SIZE.x / 2.0f;
			startPos.y += level.getSize().y + SPACE;
			level.setPosition(startPos);
		}
	}
	level.lock(lock, levelNum);
	m_levels.push_back(level);
}

void LevelMenue::loadFromFile()
{	
	for (int i = 0; i < Data::getDoneLevels(); i++)
		add(false, i + 1);
	for (int i = 0; i < Data::getLockLevels(); i++)
		add(true, 0);
}

void LevelMenue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_border);
	for (auto& item : m_levels)
		target.draw(item);
}
