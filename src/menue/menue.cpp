#include "menue.h"

//=====================================		CONSTRUCOR		==================================

Menue::Menue(sf::RenderWindow& window)
{
	setDefaultSetting(window);
	m_arrowCursor.loadFromSystem(sf::Cursor::Arrow);

	m_backGround.setSize({ float(window.getSize().x),float(window.getSize().y) });
	m_backGround.setTexture(&Resources::RscPic::getPicture(Resources::PictureName::BackColor));
	
	m_sound = Resources::RssSound::getSound(Resources::SoundName::BackGround);
	m_sound.setLoop(true);
}

//=====================================		PUBLIC		==================================

void Menue::show(sf::RenderWindow& window)
{
	sf::Event event;
	m_sound.play();
	bool endLevel = false;

	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		window.draw(m_backGround);
		window.draw(*this);

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: window.close(); break;
			default: eventHandled(window, event, endLevel);			
			}
			if (endLevel)
			{
				m_sound.stop();
				return;
			}
		}	
		window.display();
	}
}

int Menue::getSelectedLevel()
{
	return m_levels.getsSelectedLevel();
}

void Menue::refresh()
{
	m_levels.refresh();
}
//=====================================		HANDELING		==================================

void Menue::eventHandled(sf::RenderWindow& window, sf::Event& event, bool& endLevel)
{
	if (m_state == MenueState::Levels)
		eventHandledLevels(window, event, endLevel);
    else if (m_state == MenueState::Instructions)
		eventHandledInstructions(window, event, endLevel);
}

void Menue::eventHandledLevels(sf::RenderWindow& window, sf::Event& event, bool &endLevel)
{
	m_controls.eventHandled(window, event);
	m_levels.eventHandled(window, event);
	replaceCursor(window, event);

	switch (m_controls.getClickedControl(event))
	{
	case Clicked::Exit:window.close(); break;
	case Clicked::Play:endLevel = true; break;
	case Clicked::Next:m_state = MenueState::Instructions; break;	
	}
}

void Menue::eventHandledInstructions(sf::RenderWindow& window, sf::Event& event, bool& endLevel)
{
	m_controls.eventHandled(window, event);
	replaceCursor(window, event);
	switch (m_controls.getClickedControl(event))
	{
	case Clicked::Exit:window.close(); break;
	case Clicked::Play:endLevel = true; break;
	case Clicked::Next:m_state = MenueState::Levels; break;
	}
}


//=====================================		PRIVATE		==================================

void Menue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_controls);
	target.draw(m_borderShape);

	if (m_state == MenueState::Instructions)
		target.draw(m_instructions);
	else
		target.draw(m_levels);
}
void Menue::replaceCursor(sf::RenderWindow& window, sf::Event& event)
{
	if (!(m_levels.getCurrentState(event) == State::Moved) && !m_controls.isMouseHovered(event))
		window.setMouseCursor(m_arrowCursor);
}

void Menue::setDefaultSetting(sf::RenderWindow& window)
{
	m_borderShape.setPosition({ float(window.getPosition().x) + MARGIN.x,float(window.getPosition().y) + MARGIN.y });
	m_borderShape.setSize({ float(window.getSize().x) - 2 * MARGIN.x,float(window.getSize().y) - 2 * MARGIN.y });
	m_borderShape.setOutlineThickness(BORDER_SIZE);
	m_borderShape.setOutlineColor(BORDER_COLOR);
	m_borderShape.setFillColor(sf::Color::Transparent);

	m_controls.setBasePosition(m_borderShape.getPosition());
	m_controls.setBaseSize(m_borderShape.getSize());

	m_levels.setPosition(m_borderShape.getPosition());
	//devide with 2.0f - origin is center
	m_levels.setSize({m_borderShape.getSize().x, m_borderShape.getSize().y - m_controls.getSize().y});

	m_instructions.setPosition(m_borderShape.getPosition());
	m_instructions.setSize({ m_borderShape.getSize().x, m_borderShape.getSize().y - m_controls.getSize().y });
}
