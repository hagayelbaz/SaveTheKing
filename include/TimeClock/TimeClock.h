#pragma once

#include <SFML/Graphics.hpp>

class Time
{
public:
	void start();	
	void startTimer(const float timeLeft);
	void addTime(const float time);//add to timer

	//get as string (to print with style) or float
	std::string getTime(const char style = ':') const;// HH:MM:SS
	float getTimeF() const;

private:
	sf::Clock m_clock;
	int getHoures() const;
	int getMinut() const;
	int getSeconds() const;
	int m_minut = 0, m_hour = 0, m_second = 0;
	float m_timeLeft = 0;
	bool m_timer = false;
};