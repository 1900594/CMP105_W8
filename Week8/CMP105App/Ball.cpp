#include "Ball.h"
Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	
	move(2, 0 * dt);
	
}

void Ball::checkBoundingCircle(GameObject* s1, GameObject* s2)
{

}