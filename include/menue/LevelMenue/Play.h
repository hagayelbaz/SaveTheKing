#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Control.h"
#include "Level.h"
#include <fstream>      


class Play : public Control
{
public:
	Play(sf::Vector2f baseSize = { 0.0f,0.0f }, sf::Vector2f basePosition = { 0.0f,0.0f });

private:
	void setDefaultSetting() override;
};