#pragma once
#include"Framework/GameObject.h"
#include"Framework/Collision.h"
class Pong: public GameObject, public Collision
{
public:

	Pong();
	~Pong();
	void update(float dt)override;
};

