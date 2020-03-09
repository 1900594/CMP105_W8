#pragma once
#include"Framework/GameObject.h"
#include"Framework/Collision.h"
class Ball : public GameObject, public Collision
{
public:
	Ball(sf::Vector2u* x);
	~Ball();
	void update(float dt) override;
	void collisionResponse(GameObject* collider) override;
	sf::Vector2u* WindX;

};

