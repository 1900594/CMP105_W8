#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"

class AABB: public GameObject, public Collision
{

public:
	AABB();
	~AABB();
	void update(float dt);

};

