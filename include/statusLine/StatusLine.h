#pragma once

#include "StatusLineGui.h"
#include "Player.h"
#include "TimeClock.h"

static class StatusLine
{
public:
	static StatusLineGui show(std::map<PlayersName, std::shared_ptr<Player>>& players, const Time time , sf::Vector2f position = { 0.0f, 0.0f }, sf::Vector2f size = { 40.0f, 40.0f });
};