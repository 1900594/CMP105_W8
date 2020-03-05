#include "Ball2.h"
Ball2::Ball2()
{

}

Ball2::~Ball2()
{

}

void Ball2::update(float dt)
{
	checkBoundingCircle;
	move(-2, 0 * dt);
	
}