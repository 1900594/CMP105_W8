#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"

class AABB: public GameObject, public Collision
{

public:
	AABB(sf::Vector2u* x);
	~AABB();
	void update(float dt);
	sf::Vector2u* WindX;
	void collisionResponse(GameObject* collider) override;
};

