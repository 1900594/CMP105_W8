#include "Ball.h"
Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	checkBoundingCircle;
	move(2, 0 * dt);
	
}
