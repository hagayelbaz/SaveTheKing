#pragma once

#include "MoveAble.h"

enum class PlayersName
{
	King,
	Thief,
	Mage,
	Solider
};

class Player : public MoveAble
{
public:
	Player(const sf::Texture& picture,const int colPicSize = 1, sf::Vector2f position = { 0.0f,0.0f }, sf::Vector2f size = { 40.0f,40.0f });
	
	virtual void move(const sf::Time deltaTime) override;
	virtual void setPosition(const sf::Vector2f position) override;
	//set arrow up to current player (or remove)
	virtual void point();
	virtual void removePoint();

	virtual PlayersName getType() = 0;

private:
	//for animation
	const int ROW_NUMBER = 4;
	int m_colPicSize;//for picture sprite
	sf::Vector2f m_currentPic;
	sf::Vector2u m_picSize;

	//for player pointer
	sf::RectangleShape m_pointShape;
	bool m_drawPoint = false;
	const double DRAW_POINT_SPEED = 0.035;//smaller->faster
	const float MIN_SCALE = 0.2;
	const sf::Vector2f SCALE_PER_TIME = { 0.9 , 0.9 };
	const sf::Vector2f RESCALE = { 1 , 1 };
	double m_drawPointTime = 0;//add time to variable


	void resetPointShape();
	void resizeArrow();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void calcCurrentPic(const sf::Time deltaTime,const sf::Vector2f diraction,const sf::Keyboard::Key key);
protected:
	void stepBack() override;

};