#include "Player.h"


//=====================================		CONSTRUCOR		==================================
Player::Player(const sf::Texture& picture,const int colPicSize, sf::Vector2f position, sf::Vector2f size)
	:MoveAble(position,size), m_colPicSize(colPicSize)
{
	resetPointShape();
	m_shape.setTexture(&picture);
	//calc for animation
	m_picSize = picture.getSize();
	m_picSize.x /= colPicSize;
	m_picSize.y /= ROW_NUMBER;

	m_shape.setTextureRect(sf::IntRect(m_picSize.x * m_currentPic.x, m_picSize.y * m_currentPic.y, m_picSize.x, m_picSize.y));
	m_lastLocation = position;
}

//=====================================		PUBLIC		==================================

void Player::move(const sf::Time deltaTime)
{
	m_drawPointTime += deltaTime.asSeconds();
	m_lastLocation = m_shape.getPosition();

	resizeArrow();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		calcCurrentPic(deltaTime, { 0.0f, -1.0f }, sf::Keyboard::Up);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		calcCurrentPic(deltaTime, { -1.0f,0.0f }, sf::Keyboard::Left);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		calcCurrentPic(deltaTime, { 0.0f,1.0f }, sf::Keyboard::Down);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		calcCurrentPic(deltaTime, { 1.0f,0.0f }, sf::Keyboard::Right);
}

void Player::setPosition(const sf::Vector2f position)
{
	GameObject::setPosition(position); 
	resetPointShape();
}

void Player::point()
{
	m_drawPoint = true;
}

void Player::removePoint()
{
	m_drawPoint = false;
}


//==================================	PRIVATE		============================================

void Player::resetPointShape()
{
	m_pointShape.setTexture(&Resources::RscPic::getPicture(Resources::PictureName::Arrow));
	m_pointShape.setSize(m_shape.getSize() * 1.5f);//a little more bigger
	
	m_pointShape.setPosition(//to middle
		{ m_shape.getPosition().x + m_shape.getSize().x / 2,
		  m_shape.getPosition().y - m_pointShape.getSize().y / 2 });

	m_pointShape.setOrigin(m_pointShape.getSize() / 2.f);
}

void Player::resizeArrow()
{
	if (m_drawPointTime < DRAW_POINT_SPEED)
		return;

	if (m_pointShape.getScale().x > MIN_SCALE)
		m_pointShape.scale(SCALE_PER_TIME);//smaller
	else
		m_pointShape.setScale(RESCALE);//restart
	
	m_drawPointTime = 0;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	GameObject::draw(target, states);
	if (m_drawPoint)
		target.draw(m_pointShape);
}

void Player::calcCurrentPic(const sf::Time deltaTime, const sf::Vector2f diraction, const sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Down: m_currentPic.y = 0; break;
	case sf::Keyboard::Up: m_currentPic.y = 1; break;
	case sf::Keyboard::Left: m_currentPic.y = 2; break;
	case sf::Keyboard::Right: m_currentPic.y = 3; break;
	}

	m_currentPic.x = (m_currentPic.x >= m_colPicSize - 1) ? 0 : m_currentPic.x + 1;//animation
	m_shape.setTextureRect(sf::IntRect(m_picSize.x * m_currentPic.x, m_picSize.y * m_currentPic.y, m_picSize.x, m_picSize.y));
	m_shape.move(diraction * getSpeed() * deltaTime.asSeconds());
	m_pointShape.move(diraction * getSpeed() * deltaTime.asSeconds());
}

//==================================	PROTECTED		============================================

void Player::stepBack()
{
	MoveAble::stepBack();

	m_pointShape.setPosition(//to middle
		{ m_shape.getPosition().x + m_shape.getSize().x / 2,
		  m_shape.getPosition().y - m_pointShape.getSize().y / 2 });
}
