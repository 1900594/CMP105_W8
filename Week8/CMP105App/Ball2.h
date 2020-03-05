#pragma once
#include"Framework/GameObject.h"
#include"Framework/Collision.h"
class Ball2: public GameObject, public Collision
{
public:
	Ball2();
	~Ball2();
	void update(float dt);
	void checkBoundingCircle(GameObject* s1, GameObject* s2);

};

