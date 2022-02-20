#include "selectLevel.h"

//=====================================		CONSTRUCOR		==================================

SelectLevel::SelectLevel(sf::Vector2f baseSize, sf::Vector2f basePosition)
{
	setDefaultSetting();
	m_text.setFont(Resources::RscFont::getFont(Resources::FontName::Arial));
}

//=====================================		SET		==================================

void SelectLevel::setSize(const sf::Vector2f size)
{
	Control::setSize(size);
	setDefaultSetting();
}

void SelectLevel::setPosition(const sf::Vector2f position)
{
	Control::setPosition(position);
	setDefaultSetting();
}

//=====================================		PUBLIC		==================================

bool SelectLevel::isLock() const
{
	return m_lock;
}

void SelectLevel::lock(bool lock, int levelNumber)
{
	m_lock = lock;
	m_text.setString(std::to_string(levelNumber));
	m_selectedLevel = levelNumber;
	setDefaultSetting();
}

int SelectLevel::getLevelNumber()
{
	return m_selectedLevel;
}

void SelectLevel::mousePressed(sf::RenderWindow& window, sf::Event& event)
{
	m_text.setFillColor(getLastState() == State::Pressed ? sf::Color::Green : sf::Color::White);
}
//=====================================		HANDELING		==================================

void SelectLevel::eventHandled(sf::RenderWindow& window, sf::Event& event)
{
	Control::eventHandled(window, event);
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:mousePressed(window, event); break;
	}
}

//=====================================		PRIVATE		==================================

void SelectLevel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Control::draw(target, states);
	if (!m_lock)
		target.draw(m_text);
}

void SelectLevel::setDefaultSetting()
{
	sf::Vector2f position = m_control.getPosition();
	m_control = sf::RectangleShape();//restart for remove texture
	m_control.setSize({60.0f,60.0f});
	m_control.setPosition(position);
	
	m_control.setTexture(&Resources::RscPic::getPicture(!m_lock ? Resources::PictureName::Level : Resources::PictureName::Lock));

	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_text.setPosition(m_control.getPosition());
}
