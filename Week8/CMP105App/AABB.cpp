#include "AABB.h"
AABB::AABB(sf::Vector2u* x)
{
	WindX = x;
}

AABB::~AABB()
{

}

void AABB::update(float dt)
{
	move(velocity * dt);

	if (getPosition().x + getSize().x >= WindX->x || getPosition().x <= 0)
	{

		setVelocity(getVelocity().x * -1, 0);

	}


}

void AABB::collisionResponse(GameObject* collider)
{
	velocity.x *= -1;
}