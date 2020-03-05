#pragma once
#include"Framework/GameObject.h"
#include"Framework/Collision.h"
class Ball : public GameObject, public Collision
{
public:
	Ball();
	~Ball();
	void update(float dt);
};

