#pragma once
#include "GameObject.h"
#include "CollisionManager.h"
#include "BoxCollider.h"

class Tank :
	public GameObject
{
public:
	Tank(const char * textureName);

	void Update(float deltaTime);
};

