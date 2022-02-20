
#include "TimeClock.h"

//=====================================		PUBLIC		==================================

void Time::start()
{
	m_timer = false;
	m_clock.restart();
}

void Time::startTimer(const float timeLeft)
{
	m_timer = true;
	m_clock.restart();
	m_timeLeft = timeLeft;
}

float Time::getTimeF() const
{
	return (m_timer) ? m_timeLeft - (int)m_clock.getElapsedTime().asSeconds() : (int)m_clock.getElapsedTime().asSeconds();
}

std::string Time::getTime(const char style) const
{
	std::string hu = getHoures() < 10 ? "0" + std::to_string(getHoures()) : std::to_string(getHoures());
	std::string mi = getMinut() < 10 ? "0" + std::to_string(getMinut()) : std::to_string(getMinut());
	std::string se = getSeconds() % 60 < 10 ? "0" + std::to_string(getSeconds() % 60) : std::to_string(getSeconds() % 60);
	return std::string(hu + style + mi + style + se);
}

void Time::addTime(const float time)
{
	m_timeLeft += time;
}

//=====================================		PRIVATE		==================================

int Time::getHoures() const
{
	return getMinut() / 60;
}

int Time::getMinut() const
{
	return getSeconds() / 60;
}

int Time::getSeconds() const
{
	return (m_timer) ? m_timeLeft - (int)m_clock.getElapsedTime().asSeconds() : (int)m_clock.getElapsedTime().asSeconds();
}