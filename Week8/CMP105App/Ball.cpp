#include "Ball.h"
Ball::Ball(sf::Vector2u* x)
{
	WindX = x;
}

Ball::~Ball()
{
}

void Ball::update(float dt)
{
	
	move(velocity * dt);


	if (getPosition().x + getSize().x >= WindX->x || getPosition().x <= 0)
	{
		
		setVelocity(getVelocity().x * -1, 0);

	}
	
}

void Ball::collisionResponse(GameObject* collider)
{
	velocity.x *= -1;
}