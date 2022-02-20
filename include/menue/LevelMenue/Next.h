#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Control.h"
#include "Level.h"


class Next : public Control
{
public:
	Next(sf::Vector2f baseSize = { 0.0f,0.0f }, sf::Vector2f basePosition = { 0.0f,0.0f });

private:
	void setDefaultSetting();
};