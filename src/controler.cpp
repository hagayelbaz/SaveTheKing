#pragma once

#include "controler.h"

//=====================================		CONSTRUCOR		==================================

Controler::Controler()
    : m_window(sf::VideoMode::getDesktopMode(), "Save The King!!"), m_currentLevel(Level(1)) ,m_levelManager(m_window)
{
    
}

//=====================================		PUBLIC		==================================

void Controler::run()
{  
    //windows will closed from menue / game
    while (m_window.isOpen())
    {              
        //show menue for select level or see instruction
        m_levelManager.show(m_window);
        //get selected level
        m_currentLevel = m_levelManager.getLevel();
        //if selected level is not leagel , continue
        if (!m_currentLevel.isLegal()) continue;
        //else - set level to game manager
        m_gameManager.setLevel(m_currentLevel);
        //and show
        m_gameManager.show(m_window);
    }
}
